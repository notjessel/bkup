const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#121022", /* black   */
  [1] = "#da0098", /* red     */
  [2] = "#E51CB6", /* green   */
  [3] = "#CD3ABE", /* yellow  */
  [4] = "#bd93f9", /* blue    */
  [5] = "#AF1CC8", /* magenta */
  [6] = "#8822E4", /* cyan    */
  [7] = "#f8f8f2", /* white   */

  /* 8 bright colors */
  [8]  = "#9e5f97",  /* black   */
  [9]  = "#da0098",  /* red     */
  [10] = "#E51CB6", /* green   */
  [11] = "#CD3ABE", /* yellow  */
  [12] = "#bd93f9", /* blue    */
  [13] = "#AF1CC8", /* magenta */
  [14] = "#8822E4", /* cyan    */
  [15] = "#f8f8f2", /* white   */

  /* special colors */
  [256] = "#121022", /* background */
  [257] = "#f8f8f2", /* foreground */
  [258] = "#f8f8f2",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
