#include <3ds.h>
#include <stdio.h>
#include <string.h>

char program[4096] = {(char)0};

int main(int argc, char **argv) {
	gfxInitDefault();
	consoleInit(GFX_TOP,NULL);
	printf("Press Start to exit.");
	while (aptMainLoop()) {
		gspWaitForVBlank();
		hidScanInput();
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break;
		if (kDown & KEY_B) {
			strcat(program,">");
		//	printf("\x1b[2;0%s",program);
		}
		if (kDown & KEY_A) {
			strcat(program,"<");
		}
		if (kDown & KEY_Y) {
			strcat(program,"+");
		}
		if (kDown & KEY_X) {
			strcat(program,"-");
		}
		if (kDown & KEY_UP) {
			strcat(program,".");
		}
		if (kDown & KEY_LEFT) {
			strcat(program,"[");
		}
		if (kDown & KEY_RIGHT) {
			strcat(program,"]");
		}
		printf("\x1b[2;0H%s",program);
		gfxFlushBuffers();
		gfxSwapBuffers();
	}
	gfxExit();
	return 0;
}
