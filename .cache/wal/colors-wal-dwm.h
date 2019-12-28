static const char norm_fg[] = "#f7f7f7";
static const char norm_bg[] = "#0A0807";
static const char norm_border[] = "#0A0807";

static const char sel_fg[] = "#0A0807";
static const char sel_bg[] = "#F85C8E";
static const char sel_border[] = "#F85C8E";

static const char tit_fg[] = "#f7f7f7";
static const char tit_bg[] = "#0A0807";
static const char tit_border[] = "#0A0807";

static const char war_fg[] = "#73863B";
static const char war_bg[] = "#0A0807";
static const char war_border[] = "#0A0807";

static const char urg_fg[] = "#E90F58";
static const char urg_bg[] = "#0A0807";
static const char urg_border[] = "#0A0807";

static const char *colors[][5]      = {
    /*               fg           bg         border                         */
    [SchemeNorm]   = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]    = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [SchemeTitle]  = { tit_fg,      tit_bg,    tit_border },
    [SchemeWarn]   = { war_fg,      war_bg,    war_border },
    [SchemeUrgent] = { urg_fg,      urg_bg,    urg_border },
};
