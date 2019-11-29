static const char norm_fg[] = "{color15}";
static const char norm_bg[] = "{color0}";
static const char norm_border[] = "{color0}";

static const char sel_fg[] = "{color0}";
static const char sel_bg[] = "{color4}";
static const char sel_border[] = "{color4}";

static const char tit_fg[] = "{color15}";
static const char tit_bg[] = "{color0}";
static const char tit_border[] = "{color0}";

static const char war_fg[] = "{color11}";
static const char war_bg[] = "{color0}";
static const char war_border[] = "{color0}";

static const char urg_fg[] = "{color1}";
static const char urg_bg[] = "{color0}";
static const char urg_border[] = "{color0}";

static const char *colors[][5]      = {{
    /*               fg           bg         border                         */
    [SchemeNorm]   = {{ norm_fg,     norm_bg,   norm_border }}, // unfocused wins
    [SchemeSel]    = {{ sel_fg,      sel_bg,    sel_border }},  // the focused win
    [SchemeTitle]  = {{ tit_fg,      tit_bg,    tit_border }},
    [SchemeWarn]   = {{ war_fg,      war_bg,    war_border }},
    [SchemeUrgent] = {{ urg_fg,      urg_bg,    urg_border }},
}};
