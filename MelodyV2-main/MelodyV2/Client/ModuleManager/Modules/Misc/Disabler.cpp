#include "Disabler.h"

#include "../../../../Utils/Timerutils.h"
#include <cmath>
#include <math.h>
Disabler::Disabler() : Module("Disabler", "Disable the anticheat", Category::MISC) {
    addEnumSetting("Server", "What server do you want this to works on", { "Lifeboat", "CubeCraft" }, &Mode);
}
float lerp(float endPoint, float current, float speed) {
    if (speed < 0.0) speed = 0.0;
    else if (speed > 1.0) speed = 1.0;

    float dif = std::max(endPoint, current) - std::min(endPoint, current);
    float factor = dif * speed;
    return current + (endPoint > current ? factor : -factor);
}
static __int64 ms;
static __int64 prevMS = 0;
static __int64 timeMS = -1;
static __int64 getCurrentMs() {
    FILETIME f;
    GetSystemTimeAsFileTime(&f);
    (long long)f.dwHighDateTime;
    __int64 nano = ((__int64)f.dwHighDateTime << 32LL) + (__int64)f.dwLowDateTime;
    return (nano - 116444736000000000LL) / 10000;
}
static __int64 lastMS = getCurrentMs();
static bool hasTimePassed(__int64 ms) {
    return getCurrentMs() >= timeMS + ms;
}

static __int64 getTime() {
    return getCurrentMs();
}

static void reset2() {
    prevMS = getTime();
}

static __int64 getDifference() {
    return getTime() - prevMS;
}

static void setDifference(__int64 difference) {
    prevMS = getTime() - difference;
}

static void resetTime() {
    lastMS = getCurrentMs();
    timeMS = getCurrentMs();
}

static __int64 getElapsedTime1() {
    return (getCurrentMs() - timeMS);
}

static bool hasTimedElapsed(__int64 time, bool reset) {
    if (getCurrentMs() - lastMS > time) {
        if (reset)
            resetTime();
        return true;
    }
    return false;
}

static void reset1() {
    ms = getCurrentMs();
}

static bool elapsed(__int64 milliseconds) {
    return (getCurrentMs() - ms) > milliseconds;
}

static __int64 getElapsedTime() {
    return getCurrentMs() - ms;
}
void Disabler::onSendPacket(Packet* packet, bool& shouldCancel) {
    if (Mode == 0 && (packet->getName() == "PlayerAuthInputPacket" || packet->getName() == "MovePlayerPacket")) {
        auto* paip = static_cast<PlayerAuthInputPacket*>(packet);
        auto* mpp = static_cast<MovePlayerPacket*>(packet);

        if (paip) {
            float perc = static_cast<float>(paip->ticksAlive % (12 * 2)) / (12 * 2.0f);
            paip->position.y = lerp(paip->position.y, paip->position.y - 1.0f, perc);
            paip->downVelocity = -(1.0f / (12 * 2.0f));
            if (paip->ticksAlive % 12 == 0 || paip->ticksAlive % 12 == 12) {
                paip->inputData |= AuthInputAction::START_JUMPING;
            }
            paip->inputData |= AuthInputAction::JUMPING;
        }

        if (mpp) {
            float perc = static_cast<float>(mpp->tick % 24) / 24.0f;
            mpp->position.y = lerp(mpp->position.y, mpp->position.y - 1.0f, perc);
            mpp->onGround = true;
        }
    }
    if (Mode == 1) {
        if (packet->getName() == "PlayerAuthInputPacket") {
            auto* paip = (PlayerAuthInputPacket*)packet;
            auto* mpp = (MovePlayerPacket*)packet;
            auto pos = mc.getLocalPlayer()->getPosition();

            float poy = pos->y;

            int32_t tick = paip->ticksAlive % (12 * 2);

            if (12 == 12) {
                paip->position = pos->add(0, 0, 0);
                float reverse = 0.2 * -6.6;
                auto pos2 = mc.getLocalPlayer()->getPosition();
                if (hasTimedElapsed(250, true)) paip->position = (pos2->add((0.f, reverse, 0.f)));

            }
            if ((paip->inputData & AuthInputAction::SPRINTING) == AuthInputAction::SPRINTING) {
                paip->playMode == ClientPlayMode::SCREEN;
            }
        }
        /* if (mc.getLocalPlayer()->isOnGround()) {

             Vector3<float> velocity = player->stateVectorComponent->velocity;
             Vector2<float> playerRots = player->rotationComponent->Get();
             Vector1<float> newYaw = modYawByInputs(playerRots.y);
             Vector2<float> newAngles(playerRots.x, newYaw.x);
             Vector3<float> rotatedVelocity = velocity.rotateXYZ(newAngles);
             player->stateVectorComponent->velocity = rotatedVelocity;
             paip->position.y = velocity.y;
         }
         ci->packetSender->sendToServer(paip);
         ci->packetSender->sendToServer(mpp);*/  // not finish on the cubecraft i know the method but i dont know how to implement in this base yet
    }


}