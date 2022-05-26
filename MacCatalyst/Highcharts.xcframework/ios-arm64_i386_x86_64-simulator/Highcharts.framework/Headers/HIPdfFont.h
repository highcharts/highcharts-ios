/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Settings for a custom font for the exported PDF, when using the `offline-exporting` module. This is used for languages containing non-ASCII characters, like Chinese, Russian, Japanese etc. As described in the [jsPDF docs](https://github.com/parallax/jsPDF#use-of-unicode-characters--utf-8), the 14 standard fonts in PDF are limited to the ASCII-codepage. Therefore, in order to support other text in the exported PDF, one or more TTF font files have to be passed on to the exporting module. See more in [the docs](https://www.highcharts.com/docs/export-module/client-side-export).

**Try it**

* [Download PDF in a language containing non-Latin characters.](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/exporting/offline-download-pdffont/)
*/
@interface HIPdfFont: HIChartsJSONSerializable

/**
The TTF font file for normal `font-style`. If font variations like `bold` or `italic` are not defined, the `normal` font will be used for those too.
*/
@property(nonatomic, readwrite) NSString *normal;
/**
The TTF font file for bold text.
*/
@property(nonatomic, readwrite) NSString *bold;
/**
The TTF font file for italic text.
*/
@property(nonatomic, readwrite) NSString *italic;
/**
The TTF font file for bold and italic text.
*/
@property(nonatomic, readwrite) NSString *bolditalic;

-(NSDictionary *)getParams;

@end
