/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HITheme.h"
#import "HIColor.h"


/**
A collection of options for buttons appearing in the exporting module. In styled mode, the buttons are styled with the `.highcharts-contextbutton` and `.highcharts-button-symbol` classes.
*/
@interface HIButtonOptions: HIChartsJSONSerializable

/**
The color of the symbol's stroke or line.

**Try it**

* [Blue symbol stroke](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-symbolstroke/)
*/
@property(nonatomic, readwrite) HIColor *symbolStroke;
/**
Fill color for the symbol within the button.

**Try it**

* [Blue symbol stroke for one of the buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-symbolfill/)
*/
@property(nonatomic, readwrite) HIColor *symbolFill;
/**
A text string to add to the individual button.

**Defaults to** `null`.

**Try it**

* [Full text button](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-text/)
* [Combined symbol and text](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/buttons-text-symbol/)
*/
@property(nonatomic, readwrite) NSString *text;
/**
Alignment for the buttons.

**Try it**

* [Center aligned](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-align/)
*/
@property(nonatomic, readwrite) NSString *align;
/**
Whether to enable buttons.

**Defaults to** `true`.

**Try it**

* [Exporting module loaded but buttons disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-enabled/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
A configuration object for the button theme. The object accepts SVG properties like `stroke-width`, `stroke` and `fill`. Tri-state button styles are supported by the `states.hover` and `states.select` objects.

**Try it**

* [Theming the buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-theme/)
*/
@property(nonatomic, readwrite) HITheme *theme;
/**
Pixel height of the buttons.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *height;
/**
The pixel width of the button.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
The pixel spacing between buttons.
*/
@property(nonatomic, readwrite) NSNumber *buttonSpacing;
/**
The pixel size of the symbol on the button.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *symbolSize;
/**
The vertical offset of the button's position relative to its `verticalAlign`.

**Defaults to** `0`.

**Try it**

* [Buttons at lower right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-verticalalign/)
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
The vertical alignment of the buttons. Can be one of `"top"`, `"middle"` or `"bottom"`.

**Try it**

* [Buttons at lower right](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-verticalalign/)
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
The y position of the center of the symbol inside the button.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *symbolY;
/**
The x position of the center of the symbol inside the button.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *symbolX;
/**
The pixel stroke width of the symbol on the button.

**Try it**

* [Bigger buttons](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/navigation/buttonoptions-height/)
*/
@property(nonatomic, readwrite) NSNumber *symbolStrokeWidth;

-(NSDictionary *)getParams;

@end
