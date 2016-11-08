#define SCREEN_ADDRESS (0xa000U)
#define COLOUR_RAM_ADDRESS (0x1f800)
#define FOOTER_ADDRESS (SCREEN_ADDRESS+24*80)

#define FOOTER_COPYRIGHT     0
#define FOOTER_BLANK         1
#define FOOTER_NOMOREBUFFERS 2
#define FOOTER_OUTOFMEM      3
#define FOOTER_BUFFERTOOBIG  4
#define FOOTER_LINETOOLONG   5
#define FOOTER_FATAL         6
#define FOOTER_DISKERROR     7
#define FOOTER_LOADEDLINES   8
#define FOOTER_MAX           8

#define REVERSE_VIDEO 0x80
#define NORMAL_VIDEO 0x00

#define ATTRIB_REVERSE 0x20
#define ATTRIB_BLINK 0x10
#define ATTRIB_UNDERLINE 0x80
#define ATTRIB_HIGHLIGHT 0x40

#define COLOUR_BLACK 0
#define COLOUR_WHITE 1
#define COLOUR_RED 2
#define COLOUR_CYAN 3
#define COLOUR_PURPLE 4
#define COLOUR_GREEN 5
#define COLOUR_BLUE 6
#define COLOUR_YELLOW 7
#define COLOUR_ORANGE 8
#define COLOUR_BROWN 9
#define COLOUR_PINK 10
#define COLOUR_GREY1 11
#define COLOUR_DARKGREY 11
#define COLOUR_GREY2 12
#define COLOUR_GREY 12
#define COLOUR_MEDIUMGREY 12
#define COLOUR_LIGHTGREEN 13
#define COLOUR_LIGHTBLUE 14
#define COLOUR_GREY3 15
#define COLOUR_LIGHTGREY 15

void setup_screen(void);

void display_footer(unsigned char index);
void footer_save(void);
void footer_restore(void);

void mungedascii_to_screen_80(unsigned char *p, unsigned char bits);
void ascii_to_screen_80(unsigned char *p, unsigned char bits);
void ascii_to_screen_segment(unsigned char *p,unsigned char count,unsigned char bits);

void screen_colour_line(unsigned char line,unsigned char colour);
#define screen_colour_line_segment(LA,W,C) lfill(LA+(0x1f800-SCREEN_ADDRESS),C,W)

void screen_hex(unsigned int addr,long value);
void screen_decimal(unsigned int addr,unsigned int value,unsigned char bits);

extern unsigned char ascii_map[256];
#define ascii_to_screen(X) ascii_map[X]

void fatal_error(unsigned char *filename, unsigned int line_number);
#define FATAL_ERROR fatal_error(__FILE__,__LINE__)
