/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIExportingButtons.h"


/**
* description: Options for the exporting module. For an overview on the matter, see http://www.highcharts.com/docs/export-module/export-module-overview : the docs.
*/
@interface HIExporting: HIChartsJSONSerializable

/**
* description: Default MIME type for exporting if chart.exportChart() is called without specifying a type option. Possible values are image/png, image/jpeg, application/pdf and image/svg+xml.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/type/ : Default type set to 
* accepted values: ["image/png", "image/jpeg", "application/pdf", "image/svg+xml"]
* default: image/png
*/
@property(nonatomic, readwrite) NSString *type;
/**
* description: Options for the export related buttons, print and export. In addition to the default buttons listed here, custom buttons can be added. See navigation.buttonOptions for general options.
*/
@property(nonatomic, readwrite) HIExportingButtons *buttons;
/**
* description: Analogous to sourceWidth
*/
@property(nonatomic, readwrite) NSNumber *sourceHeight;
/**
* description: Whether or not to fall back to the export server if the offline-exporting module is unable to export the chart on the client side.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *fallbackToExportServer;
/**
* description: The width of the original chart when exported, unless an explicit chart.width is set. The width exported raster image is then multiplied by scale.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/sourcewidth/ : Source size demo
*/
@property(nonatomic, readwrite) NSNumber *sourceWidth;
/**
* description: Whether to enable the exporting module. Disabling the module will hide the context button, but API methods will still be available.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/enabled-false/ : Exporting module is loaded but disabled
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: The URL for the server module converting the SVG string to an image format. By default this points to Highchart's free web service.
* default: https://export.highcharts.com
*/
@property(nonatomic, readwrite) NSString *url;
/**
* description: Experimental setting to allow HTML inside the chart (added through the useHTML options), directly in the exported image. This allows you to preserve complicated HTML structures like tables or bi-directional text in exported charts.
Disclaimer: The HTML is rendered in a foreignObject tag in the generated SVG. The official export server is based on PhantomJS, which supports this, but other SVG clients, like Batik, does not support it. This also applies to downloaded SVG that you want to open in a desktop client.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowHTML;
/**
* description: The filename, without extension, to use for the exported chart.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/filename/ : Custom file name
* default: chart
*/
@property(nonatomic, readwrite) NSString *filename;
/**
* description: Defines the scale or zoom factor for the exported image compared to the on-screen display. While for instance a 600px wide chart may look good on a website, it will look bad in print. The default scale of 2 makes this chart export to a 1200px PNG or JPG. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/scale/ : Scale demonstrated
* default: 2
*/
@property(nonatomic, readwrite) NSNumber *scale;
/**
* description: An object containing additional attributes for the POST form that sends the SVG to the export server. For example, a target can be set to make sure the generated image is received in another frame, or a custom enctype or encoding can be set.
*/
@property(nonatomic, readwrite) id formAttributes;
/**
* description: Path where Highcharts will look for export module dependencies to load on demand if they don't already exist on window.

Should currently point to location of https://github.com/canvg/canvg : CanVG library, https://github.com/canvg/canvg : RGBColor.js, https://github.com/yWorks/jsPDF : jsPDF and https://github.com/yWorks/svg2pdf.js : svg2pdf.js, required for client side export in certain browsers.
* default: https://code.highcharts.com/{version}/lib
*/
@property(nonatomic, readwrite) NSString *libURL;
/**
* description: Additional chart options to be merged into an exported chart. For example, a common use case is to add data labels to improve readaility of the exported chart, or to add a printer-friendly color scheme.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/chartoptions-data-labels/ : Added data labels.
* default: null
*/
@property(nonatomic, readwrite) id chartOptions;
/**
* description: Function to call if the offline-exporting module fails to export a chart on the client side, and fallbackToExportServer is disabled. If left undefined, an exception is thrown instead.
* default: undefined
*/
@property(nonatomic, readwrite) NSString /* Function */ *error;
/**
* description: When printing the chart from the menu item in the burger menu, if the on-screen chart exceeds this width, it is resized. After printing or cancelled, it is restored. The default width makes the chart fit into typical paper format. Note that this does not affect the chart when printing the web page as a whole.
* default: 780
*/
@property(nonatomic, readwrite) NSNumber *printMaxWidth;
/**
* description: The pixel width of charts exported to PNG or JPG. As of Highcharts 3.0, the default pixel width is a function of the chart.width or exporting.sourceWidth and the exporting.scale.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/exporting/width/ : Export to 200px wide images
* default: undefined
*/
@property(nonatomic, readwrite) NSNumber *width;

-(NSDictionary *)getParams;

@end
