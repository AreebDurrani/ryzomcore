
const char *a_arbfp1 = 
	"!!ARBfp1.0\n"
	//"# cgc version 3.1.0013, build date Apr 18 2012\n"
	//"# command line args: -profile arbfp1\n"
	//"# source file: fxaa_fp.cg\n"
	//"#vendor NVIDIA Corporation\n"
	//"#version 3.1.0.13\n"
	//"#profile arbfp1\n"
	//"#program fxaa_fp\n"
	//"#semantic fxaa_fp.fxaaConsoleRcpFrameOpt\n"
	//"#semantic fxaa_fp.fxaaConsoleRcpFrameOpt2\n"
	//"#semantic fxaa_fp.nlTex0 : TEX0\n"
	//"#var float2 pos : $vin.TEXCOORD0 : TEX0 : 0 : 1\n"
	//"#var float4 fxaaConsolePosPos : $vin.TEXCOORD1 : TEX1 : 1 : 1\n"
	//"#var float4 fxaaConsoleRcpFrameOpt :  : c[0] : 2 : 1\n"
	//"#var float4 fxaaConsoleRcpFrameOpt2 :  : c[1] : 3 : 1\n"
	//"#var sampler2D nlTex0 : TEX0 : texunit 0 : 4 : 1\n"
	//"#var float4 oCol : $vout.COLOR : COL : 5 : 1\n"
	//"#const c[2] = 0.125 0 8 0.001953125\n"
	//"#const c[3] = -2 2 0.5\n"
	"PARAM c[4] = { program.env[0..1],\n"
	"		{ 0.125, 0, 8, 0.001953125 },\n"
	"		{ -2, 2, 0.5 } };\n"
	"TEMP R0;\n"
	"TEMP R1;\n"
	"TEMP R2;\n"
	"TEMP R3;\n"
	"TEMP R4;\n"
	"TEMP R5;\n"
	"TEX R0.w, fragment.texcoord[1].zyzw, texture[0], 2D;\n"
	"ADD R0.x, R0.w, c[2].w;\n"
	"TEX R1.w, fragment.texcoord[1].xwzw, texture[0], 2D;\n"
	"TEX R0.w, fragment.texcoord[1], texture[0], 2D;\n"
	"ADD R0.y, R1.w, -R0.x;\n"
	"ADD R0.z, R0.w, R0.y;\n"
	"TEX R2.w, fragment.texcoord[1].zwzw, texture[0], 2D;\n"
	"ADD R0.y, -R0.w, R0;\n"
	"ADD R1.z, -R2.w, R0;\n"
	"ADD R1.x, R2.w, R0.y;\n"
	"MOV R1.y, c[2];\n"
	"DP3 R0.y, R1, R1;\n"
	"RSQ R0.y, R0.y;\n"
	"MUL R2.xy, R0.y, R1.xzzw;\n"
	"MAD R3.xy, R2, c[0].zwzw, fragment.texcoord[0];\n"
	"ABS R0.z, R2.y;\n"
	"ABS R0.y, R2.x;\n"
	"MIN R0.y, R0, R0.z;\n"
	"RCP R0.y, R0.y;\n"
	"MUL R1.xy, R0.y, R2;\n"
	"MUL R1.xy, R1, c[2].x;\n"
	"MIN R1.xy, R1, c[3].y;\n"
	"MIN R0.y, R0.w, R1.w;\n"
	"TEX R4, R3, texture[0], 2D;\n"
	"MAD R2.xy, -R2, c[0].zwzw, fragment.texcoord[0];\n"
	"TEX R3, R2, texture[0], 2D;\n"
	"ADD R3, R3, R4;\n"
	"MAX R1.xy, R1, c[3].x;\n"
	"MAD R2.xy, R1, c[1].zwzw, fragment.texcoord[0];\n"
	"MAD R1.xy, -R1, c[1].zwzw, fragment.texcoord[0];\n"
	"MUL R5, R3, c[3].z;\n"
	"TEX R4, R2, texture[0], 2D;\n"
	"TEX R3, R1, texture[0], 2D;\n"
	"MIN R0.z, R0.x, R2.w;\n"
	"MIN R1.x, R0.y, R0.z;\n"
	"MAX R0.y, R0.x, R2.w;\n"
	"MAX R0.x, R0.w, R1.w;\n"
	"MAX R2.x, R0, R0.y;\n"
	"ADD R3, R3, R4;\n"
	"MAD R3, R3, c[3].z, R5;\n"
	"MUL R3, R3, c[3].z;\n"
	"SLT R1.z, R2.x, R3.w;\n"
	"SLT R1.y, R3.w, R1.x;\n"
	"TEX R0, fragment.texcoord[0], texture[0], 2D;\n"
	"ADD_SAT R1.y, R1, R1.z;\n"
	"MIN R1.z, R0.w, R1.x;\n"
	"MAX R1.x, R2, R0.w;\n"
	"ADD R2.y, R1.x, -R1.z;\n"
	"CMP R1, -R1.y, R5, R3;\n"
	"MAD R2.x, R2.y, c[2].z, -R2;\n"
	"CMP result.color, R2.x, R0, R1;\n"
	"END\n";
	//"# 51 instructions, 6 R-regs\n"

const char *a_ps_2_0 = 
	"ps_2_x\n"
	// cgc version 3.1.0013, build date Apr 18 2012
	// command line args: -profile ps_2_x
	// source file: fxaa_fp.cg
	//vendor NVIDIA Corporation
	//version 3.1.0.13
	//profile ps_2_x
	//program fxaa_fp
	//semantic fxaa_fp.fxaaConsoleRcpFrameOpt
	//semantic fxaa_fp.fxaaConsoleRcpFrameOpt2
	//semantic fxaa_fp.nlTex0 : TEX0
	//var float2 pos : $vin.TEXCOORD0 : TEX0 : 0 : 1
	//var float4 fxaaConsolePosPos : $vin.TEXCOORD1 : TEX1 : 1 : 1
	//var float4 fxaaConsoleRcpFrameOpt :  : c[0] : 2 : 1
	//var float4 fxaaConsoleRcpFrameOpt2 :  : c[1] : 3 : 1
	//var sampler2D nlTex0 : TEX0 : texunit 0 : 4 : 1
	//var float4 oCol : $vout.COLOR : COL : 5 : 1
	//const c[2] = 0.001953125 0 0.125 2
	//const c[3] = -2 0.5 0 1
	//const c[4] = 8
	"dcl_2d s0\n"
	"def c2, 0.00195313, 0.00000000, 0.12500000, 2.00000000\n"
	"def c3, -2.00000000, 0.50000000, 0.00000000, 1.00000000\n"
	"def c4, 8.00000000, 0, 0, 0\n"
	"dcl t1\n"
	"dcl t0.xy\n"
	"mov r0.xy, t1.zyzw\n"
	"texld r0, r0, s0\n"
	"mov r0.xy, t1.xwzw\n"
	"texld r5, t1, s0\n"
	"texld r4, r0, s0\n"
	"add r4.x, r0.w, c2\n"
	"mov r0.xy, t1.zwzw\n"
	"texld r3, r0, s0\n"
	"add r0.w, r4, -r4.x\n"
	"add r0.x, r5.w, r0.w\n"
	"add r0.z, -r3.w, r0.x\n"
	"add r0.x, -r5.w, r0.w\n"
	"add r0.x, r3.w, r0\n"
	"mov r0.y, c2\n"
	"dp3 r0.y, r0, r0\n"
	"rsq r0.y, r0.y\n"
	"mul r0.zw, r0.y, r0.xyxz\n"
	"mad r1.xy, -r0.zwzw, c0.zwzw, t0\n"
	"texld r1, r1, s0\n"
	"abs r0.y, r0.w\n"
	"abs r0.x, r0.z\n"
	"min r0.x, r0, r0.y\n"
	"rcp r0.x, r0.x\n"
	"mul r0.xy, r0.x, r0.zwzw\n"
	"mul r0.xy, r0, c2.z\n"
	"min r2.xy, r0, c2.w\n"
	"mad r0.xy, r0.zwzw, c0.zwzw, t0\n"
	"texld r0, r0, s0\n"
	"add r0, r1, r0\n"
	"max r1.xy, r2, c3.x\n"
	"mul r2, r0, c3.y\n"
	"mad r0.xy, r1, c1.zwzw, t0\n"
	"mad r1.xy, -r1, c1.zwzw, t0\n"
	"texld r0, r0, s0\n"
	"texld r1, r1, s0\n"
	"add r0, r1, r0\n"
	"mad r0, r0, c3.y, r2\n"
	"mul r1, r0, c3.y\n"
	"min r0.y, r4.x, r3.w\n"
	"min r0.x, r5.w, r4.w\n"
	"min r3.y, r0.x, r0\n"
	"add r0.x, -r3.y, r1.w\n"
	"max r0.z, r4.x, r3.w\n"
	"max r0.y, r5.w, r4.w\n"
	"max r3.x, r0.y, r0.z\n"
	"cmp r3.z, r0.x, c3, c3.w\n"
	"add r3.w, r3.x, -r1\n"
	"cmp r3.w, r3, c3.z, c3\n"
	"add_pp_sat r3.z, r3, r3.w\n"
	"texld r0, t0, s0\n"
	"min r3.w, r0, r3.y\n"
	"max r3.y, r3.x, r0.w\n"
	"cmp r1, -r3.z, r1, r2\n"
	"add r3.y, r3, -r3.w\n"
	"mad r2.x, r3.y, c4, -r3\n"
	"cmp r0, r2.x, r1, r0\n"
	"mov oC0, r0\n";
