#include "playSound.h"

void PlaySoundF(LPCWSTR wav)
{
	if (!PlaySoundW(wav, NULL, SND_ASYNC | SND_FILENAME))
	{
		cout << "Failed to play sound." << endl;
	}
	
}
