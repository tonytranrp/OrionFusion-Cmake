#include "AutoEmote.h"
#include <cstdlib>
#include <ctime>
int Emotedelaytick = 0;
int currentEmoteIndex = 0;
AutoEmote::AutoEmote() : Module("AutoEmote", "Auto-doing Random Emote", Category::RENDER) {
	addSlider<int>("Emote delay", "NULL", ValueType::INT_T, &EmoteDelay, 0, 20);
}
std::vector<std::string> emoteUUIDs = {
	"18891e6c-bb3d-47f6-bc15-265605d86525",
	"c2a47805-c792-4882-a56d-17c80b6c57a8",
	"f9345ebb-4ba3-40e6-ad9b-6bfb10c92890",
	"e7bb3d8c-811d-442a-bfc5-775556d05d7a",
	"a0b1a9f2-0ea4-48d0-8641-ada998beee4d",
	"79452f7e-ffa0-470f-8283-f5063348471d",
	"819f2f36-2a16-440c-8e46-94c6b003a2e0",
	"7a314ecf-f94c-42c0-945f-76903c923808",
	"ddfa6f0e-88ca-46de-b189-2bd5b18e96a0",
	"1dbaa006-0ec6-42c3-9440-a3bfa0c6fdbe",
	"9f5d4732-0513-4a0a-8ea2-b6b8d7587e74",
	"5cf9d5a3-6fa0-424e-8ae4-d1f877b836da",
	"59d9e78c-f0bb-4f14-9e9b-7ab4f58ffbf5",
	"3d10a8c7-213c-4fbe-a208-a0f7990d5bbb",
	"af61c759-6252-431d-a7de-94d477cfb54c",
	"495d686a-4cb3-4f0b-beb5-bebdcb95eed9",
	"f99ccd35-ebda-4122-b458-ff8c9f9a432f",
	"beb74219-e90c-46aa-8a4b-a1c175f6cab5",
	"f15ceb56-6651-41c0-8bd5-087951204d81",
	"a12252fa-4ec8-42e0-a7d0-d44fbc90d753",
	"86b34976-8f41-475b-a386-385080dc6e83",
	"a98ea25e-4e6a-477f-8fc2-9e8a18ab7004",
	"2647f538-6fc6-4775-85ae-7f6f2a8065b2",
	"71afa8ed-03b6-4808-b537-330daf9dbf50",
	"5e1ef7ed-efdf-44a9-8ace-6cca6275d80d",
	"c4d87a21-d4c4-498b-8bc1-5dd78c895e9f",
	"d9d1192d-1262-470d-bc0c-5ba46bedab72",
    "2391b018-3b8a-4bb0-9596-8edfc502d302",
	"402efb2d-6607-47f2-b8e5-bc422bcd8304",
	"6d9f24c0-6246-4c92-8169-4648d1981cbb",
	"efc2f0f5-af00-4d9e-a4b1-78f18d63be79",
	"bb6f1764-2b0b-4a3a-adfd-3334627cdee4",
	"b310ea06-0485-4ad1-8424-df271ca6ec37",
	"9c939344-f9d6-4a3a-95a5-f64dd3d94e45",
	"949c4f24-6aa6-4f2a-bad5-1b3de7e12749",
	"17428c4c-3813-4ea1-b3a9-d6a32f83afca",  // undocumented
	"13334afa-bd66-4285-b3d9-d974046db479",
	"b690c36b-bd02-45df-a60b-00c0dbbf265f",
	"5a5b2c0c-a924-4e13-a99b-4c12e3f02e1e",
	"738497ce-539f-4e06-9a03-dc528506a468",
	"e1090020-cbe0-4b64-9c41-a3b9619da029",
	"f14d652f-18ed-42dc-831f-7f6a2eab1246",
	"434489fd-ed42-4814-961a-df14161d67e0",
	"af6ad96c-5754-4cf9-a463-49a8190e6b0e",
	"d863b9cc-9f8c-498b-a8a3-7ebd542cb08e",
	"6453480a-54ac-435d-899d-4e6f7fe57591",
	"5dd129f9-cfc3-4fc1-b464-c66a03061545",
	"c2b9dd03-7258-4813-b6f5-37ef9b4a3326",
	"1e30e8f4-2991-4aac-a58a-a6bf90a080c5",
	"c4b5b251-24d3-43eb-9c05-46be246aeefb",
	"fb9b884a-b217-46a2-85fd-d3ab0f2f33e6",
	"54e2209a-41ec-4502-8500-dd51e569ab69",
	"d24f27c0-6bc8-4193-842c-8e33fdae5e8e",
	"87c039b7-7bdc-45d1-8684-e940a131ec0a",
	"b13966b3-1f7c-4f07-8ab8-9d85170203f5",
	"24444aea-cb6e-451f-90fc-b74e57cc7c5d",
	"310b41de-1c7a-4098-928d-addcd905bf65",
	"63cb3c45-b3b3-4c02-a4f3-fb4b9853dbe9",
	"85957448-e7bb-4bb4-9182-510b4428e52c",
	"6174a111-19ac-41d1-a483-0e0b37f9d049",
	"79e93b59-38f0-4796-8033-f99d7aa9334e",
	"a51f8e7c-a4dd-4ce1-9fc9-2c3cad66cede",
	"21e0054a-5bf4-468d-bfc4-fc4b49bd44ac",
	"71721c51-b7d1-46b1-b7ea-eb4c4126c3db",
	"ce5c0300-7f03-455d-aaf1-352e4927b54d",
	"2ecc0fd1-312b-4664-9bfa-a06429838706",
	"9d4019d0-db3f-4859-a579-f6c37532d2a6",
	"5d644007-3cdf-4246-b4ca-cfd7a4318a1c",
	"7102c0f7-6113-44f5-b37c-4e94841b0e81",
	"34259925-44dd-46f0-98e5-80ccebc086d0",
	"6f82688e-e549-408c-946d-f8e99b91808d",
	"a602063f-1ded-4959-b978-b5ae7f353536",
	"0c141653-1166-448b-87a2-38d0679bb549",
    "98a68056-e025-4c0f-a959-d6e330ccb5f5",
	"6bcf44bd-ff8a-48a5-9254-3983a0b0f702",
	"1ea5f771-827d-408d-ae8e-1af00d7aa416",
	"4ff73ed2-3c2f-4d74-9055-5fa24e59dc7a",
	"f1e18201-729d-472d-9e4f-5cdd7f6bba0c",
	"946f04ea-8ff0-416e-a66d-8b0d0751e8bf",
	"9a469a61-c83b-4ba9-b507-bdbe64430582",
	"70831936-d97d-48fe-a7e7-d8894e7c5507",
	"e8a91ad4-6f7a-479e-9556-e1a7c058351b",
	"b8e54924-ec3f-409c-8914-bca61fbe9242",
	"cd8c3bc6-f455-43d2-836e-62c1a19474c7",
	"daeaaa6f-db91-4461-8617-400c5d1b8646",
	"d7680c67-8e54-482a-903d-622ddb43485f",
	"a57277d5-0693-4c8a-9b5c-45c33fdf7c26",
	"7393aa53-9145-4e66-b23b-ec86def6c6f2",
	"7cec98d8-55cc-44fe-b0ae-2672b0b2bd37",
	"88dc7deb-21bb-48c3-8b5a-00757a06aef9",
	"d7519b5a-45ec-4d27-997c-89d402c6b57f",
	"51871829-e9ef-40aa-939c-b8952295d50e",
	"42fde774-37d4-4422-b374-89ff13a6535a",
	"20bcb500-af82-4c2f-9239-e78191c61375",
	"79e8cb30-c1b4-4e41-8aa8-96492c6f390c",
	"05af18ca-920f-4232-83cb-133b2d913dd6",
	"4b9b9f17-3722-4d38-a6a9-9ba0e8cf5044",
	"77053f59-c79b-4d5c-8dc5-539ed28002e9",
	"d0c60245-538e-4ea2-bdd4-33477db5aa89",
	"6b9c7731-7422-4333-950f-cf3d147ffa47",
	"4c8ae710-df2e-47cd-814d-cc7bf21a3d67",
	"c2d6091d-9f91-4a9e-badd-ef8481353cb0",
	"3f1bdf46-80b0-4a64-b631-4ac2f2491165",
};
void AutoEmote::onNormalTick(Actor* actor) {
	LocalPlayer* localPlayer = mc.getLocalPlayer();

	if (Emotedelaytick >= EmoteDelay) {
		if (currentEmoteIndex >= emoteUUIDs.size()) {
			currentEmoteIndex = 0; // Reset to the beginning if reached the end
		}

		localPlayer->playEmote(emoteUUIDs[currentEmoteIndex],true );
		currentEmoteIndex++;
		Emotedelaytick = 0;
	}
	else {
		Emotedelaytick++;
	}
}