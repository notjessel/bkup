static const char norm_fg[] = "#f8f8f2";
static const char norm_bg[] = "#121022";
static const char norm_border[] = "#121022";

static const char sel_fg[] = "#121022";
static const char sel_bg[] = "#BD93F9";
static const char sel_border[] = "#BD93F9";

static const char tit_fg[] = "#f8f8f2";
static const char tit_bg[] = "#121022";
static const char tit_border[] = "#121022";

static const char war_fg[] = "#CD3ABE";
static const char war_bg[] = "#121022";
static const char war_border[] = "#121022";

static const char urg_fg[] = "#DA0098";
static const char urg_bg[] = "#121022";
static const char urg_border[] = "#121022";

static const char *colors[][5]      = {
    /*               fg           bg         border                         */
    [SchemeNorm]   = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]    = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [SchemeTitle]  = { tit_fg,      tit_bg,    tit_border },
    [SchemeWarn]   = { war_fg,      war_bg,    war_border },
    [SchemeUrgent] = { urg_fg,      urg_bg,    urg_border },
};
