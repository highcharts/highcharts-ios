/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIButtonTheme.h"


/**
Global options that don't apply to each chart. These options, like the `lang` options, must be set using the `Highcharts.setOptions` method. ```js Highcharts.setOptions({   global: {     buttonTheme: {       fill: '#d0d0d0'     }   } }); ```
*/
@interface HIGlobal: HIChartsJSONSerializable

/**
General theme for buttons. This applies to the zoom button, exporting context menu, map navigation, range selector buttons and custom buttons generated using the `SVGRenderer.button` function. However, each of these may be overridden with more specific options.

**Try it**

* [General button theme](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/global/buttontheme)
*/
@property(nonatomic, readwrite) HIButtonTheme *buttonTheme;

-(NSDictionary *)getParams;

@end
