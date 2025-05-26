/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:size=15"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	//Nord 
//static const char col_gray1[]       = "#1e1e2e";
//static const char col_gray2[]       = "#11111b"; //unfocused border#89b4fa
//static const char col_gray3[]       = "#cdd6f4"; //text
//static const char col_gray4[]       = "#cba6f7";
//static const char col_cyan[]        = "#45475a"; //#11111b

	[SchemeNorm] = { "#cdd6f4", "#1e1e2e" }, // nf, nb
	[SchemeSel]  = { "#cdd6f4", "#11111b" }, // sf, sb
	[SchemeOut]  = { "#cba6f7", "#45475a" }, // leave as-is or adjust to taste
};
/* -l and -g options; controls number of lines and columns in grid if > 0 */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

