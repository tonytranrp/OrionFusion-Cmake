#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// COLOR                    0   xyzw        0     NONE   float   xyzw
// TEXCOORD                 0   xy          1     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0               
//
//
// Level9 shader bytecode:
//
    ps_2_0
    dcl t0  // pin<0,1,2,3>
    dcl t1.xy  // pin<4,5>
    dcl_2d s0

#line 521 "C:\Users\tony\Downloads\OrionFusion-Cmake\MelodyV2-main\out\build\x64-Debug\_deps\dxtk-src\Src\Shaders\BasicEffect.fx"
    texld r0, t1, s0
    mul r0, r0, t0  // ::PSBasicTxNoFog<0,1,2,3>
    mov oC0, r0  // ::PSBasicTxNoFog<0,1,2,3>

// approximately 3 instruction slots used (1 texture, 2 arithmetic)
ps_4_0
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v0.xyzw
dcl_input_ps linear v1.xy
dcl_output o0.xyzw
dcl_temps 1
sample r0.xyzw, v1.xyxx, t0.xyzw, s0
mul o0.xyzw, r0.xyzw, v0.xyzw
ret 
// Approximately 0 instruction slots used
#endif

const BYTE BasicEffect_PSBasicTxNoFog[] =
{
     68,  88,  66,  67, 170,  60, 
    250, 140, 167, 100, 178, 232, 
     37,  79, 135, 105,  62, 164, 
    189, 226,   1,   0,   0,   0, 
    172,   3,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
    140,   2,   0,   0,  40,   3, 
      0,   0, 120,   3,   0,   0, 
     65, 111, 110,  57,  84,   2, 
      0,   0,  84,   2,   0,   0, 
      0,   2, 255, 255,  44,   2, 
      0,   0,  40,   0,   0,   0, 
      0,   0,  40,   0,   0,   0, 
     40,   0,   0,   0,  40,   0, 
      1,   0,  36,   0,   0,   0, 
     40,   0,   0,   0,   0,   0, 
      0,   2, 255, 255, 254, 255, 
    116,   0,  68,  66,  85,  71, 
     40,   0,   0,   0, 164,   1, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 160,   0, 
      0,   0,   6,   0,   0,   0, 
    164,   0,   0,   0,   2,   0, 
      0,   0, 124,   1,   0,   0, 
    212,   0,   0,   0,  67,  58, 
     92,  85, 115, 101, 114, 115, 
     92, 116, 111, 110, 121,  92, 
     68, 111, 119, 110, 108, 111, 
     97, 100, 115,  92,  79, 114, 
    105, 111, 110,  70, 117, 115, 
    105, 111, 110,  45,  67, 109, 
     97, 107, 101,  92,  77, 101, 
    108, 111, 100, 121,  86,  50, 
     45, 109,  97, 105, 110,  92, 
    111, 117, 116,  92,  98, 117, 
    105, 108, 100,  92, 120,  54, 
     52,  45,  68, 101,  98, 117, 
    103,  92,  95, 100, 101, 112, 
    115,  92, 100, 120, 116, 107, 
     45, 115, 114,  99,  92,  83, 
    114,  99,  92,  83, 104,  97, 
    100, 101, 114, 115,  92,  66, 
     97, 115, 105,  99,  69, 102, 
    102, 101,  99, 116,  46, 102, 
    120,   0, 171, 171,  40,   0, 
      0,   0,   0,   0, 255, 255, 
    216,   1,   0,   0,   0,   0, 
    255, 255, 228,   1,   0,   0, 
      0,   0, 255, 255, 240,   1, 
      0,   0,   9,   2,   0,   0, 
    252,   1,   0,   0,   9,   2, 
      0,   0,  12,   2,   0,   0, 
      9,   2,   0,   0,  28,   2, 
      0,   0,  80,  83,  66,  97, 
    115, 105,  99,  84, 120,  78, 
    111,  70, 111, 103,   0, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0,   3,   0,   5,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0,   3,   0, 112, 105, 
    110,   0,  68, 105, 102, 102, 
    117, 115, 101,   0,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  84, 101, 120,  67, 
    111, 111, 114, 100,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   2,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     16,   1,   0,   0,  24,   1, 
      0,   0,  40,   1,   0,   0, 
     52,   1,   0,   0,   5,   0, 
      0,   0,   1,   0,   6,   0, 
      1,   0,   2,   0,  68,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
      3,   0,   1,   0,   0,   0, 
      4,   0,   5,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    212,   0,   0,   0, 228,   0, 
      0,   0,   2,   0,   0,   0, 
    244,   0,   0,   0, 212,   0, 
      0,   0,  12,   1,   0,   0, 
     84,   1,   0,   0,   2,   0, 
      0,   0, 100,   1,   0,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  49, 
     48,  46,  49,   0,  31,   0, 
      0,   2,   0,   0,   0, 128, 
      0,   0,  15, 176,  31,   0, 
      0,   2,   0,   0,   0, 128, 
      1,   0,   3, 176,  31,   0, 
      0,   2,   0,   0,   0, 144, 
      0,   8,  15, 160,  66,   0, 
      0,   3,   0,   0,  15, 128, 
      1,   0, 228, 176,   0,   8, 
    228, 160,   5,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    228, 128,   0,   0, 228, 176, 
      1,   0,   0,   2,   0,   8, 
     15, 128,   0,   0, 228, 128, 
    255, 255,   0,   0,  83,  72, 
     68,  82, 148,   0,   0,   0, 
     64,   0,   0,   0,  37,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   0,   0, 
      0,   0,  85,  85,   0,   0, 
     98,  16,   0,   3, 242,  16, 
     16,   0,   0,   0,   0,   0, 
     98,  16,   0,   3,  50,  16, 
     16,   0,   1,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   0,   0,   0,   0, 
    104,   0,   0,   2,   1,   0, 
      0,   0,  69,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  16,  16,   0, 
      1,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
    242,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70,  30, 
     16,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  73,  83, 
     71,  78,  72,   0,   0,   0, 
      2,   0,   0,   0,   8,   0, 
      0,   0,  56,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,  15, 
      0,   0,  62,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,   3,   3, 
      0,   0,  67,  79,  76,  79, 
     82,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0, 171, 
     79,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  84,  97, 114, 103, 101, 
    116,   0, 171, 171
};