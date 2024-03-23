#ifndef POKEPLATINUM_CONSTANTS_SAVEDATA_H
#define POKEPLATINUM_CONSTANTS_SAVEDATA_H

enum {
	LOAD_RESULT_EMPTY,		
	LOAD_RESULT_OK,				
	LOAD_RESULT_CORRUPT,				
	LOAD_RESULT_ERROR,			
};

enum {
	SAVE_RESULT_PROCEED,	
	SAVE_RESULT_PROCEED_FINAL,
	SAVE_RESULT_OK,					
	SAVE_RESULT_CORRUPT,					
};

#define NORMAL_LOAD_CORRUPT		(1 << 0)
#define NORMAL_LOAD_ERROR		(1 << 1)
#define FRONTIER_LOAD_CORRUPT	(1 << 2)
#define FRONTIER_LOAD_ERROR		(1 << 3)
#define VIDEO_LOAD_CORRUPT		(1 << 4)
#define VIDEO_LOAD_ERROR		(1 << 5)

#endif // POKEPLATINUM_CONSTANTS_SAVEDATA_H