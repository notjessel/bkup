const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#0A0807", /* black   */
  [1] = "#E90F58", /* red     */
  [2] = "#C05648", /* green   */
  [3] = "#73863B", /* yellow  */
  [4] = "#F85C8E", /* blue    */
  [5] = "#E6A759", /* magenta */
  [6] = "#E2DE66", /* cyan    */
  [7] = "#f7f7f7", /* white   */

  /* 8 bright colors */
  [8]  = "#a06b87",  /* black   */
  [9]  = "#E90F58",  /* red     */
  [10] = "#C05648", /* green   */
  [11] = "#73863B", /* yellow  */
  [12] = "#F85C8E", /* blue    */
  [13] = "#E6A759", /* magenta */
  [14] = "#E2DE66", /* cyan    */
  [15] = "#f7f7f7", /* white   */

  /* special colors */
  [256] = "#0A0807", /* background */
  [257] = "#f7f7f7", /* foreground */
  [258] = "#f7f7f7",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
