//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		                     /*Update Interval*/	/*Update Signal*/
    {"", "~/.config/dwmblocks/statusbar/pkgupdates",				 5,	    1},
    {"", "~/.config/dwmblocks/statusbar/clock",						 1,		1},
    {"", "~/.config/dwmblocks/statusbar/pulse",						 5,		1},
    {"", "~/.config/dwmblocks/statusbar/mpd",						 1,		1},
    {"", "~/.config/dwmblocks/statusbar/date",					     60,	1},
    {"", "~/.config/dwmblocks/statusbar/wttr",					     60,	1},
    {"", "~/.config/dwmblocks/statusbar/backlight",                  1,     1},
    {"", "~/.config/dwmblocks/statusbar/battery",					 10,	1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = '|';
