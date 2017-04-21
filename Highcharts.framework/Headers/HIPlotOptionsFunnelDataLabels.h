/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


@interface HIPlotOptionsFunnelDataLabels: HIChartsJSONSerializable

/**
* description: Whether to defer displaying the data labels until the initial series animation has finished.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *defer;
/**
* description: Whether to render the connector as a soft arc or a line with sharp break.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-softconnector-true/ : Soft,
			http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-softconnector-false/ : non soft connectors.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *softConnector;
/**
* description: For points with an extent, like columns, whether to align the data label inside the box or to the actual value point. Defaults to false in most cases, true in stacked columns.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *inside;
/**
* description: The name of a symbol to use for the border around the label. Symbols are predefined functions on the Renderer object.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-shape/ : A callout for annotations
* default: square
*/
@property(nonatomic, readwrite) NSString *shape;
/**
* description: Enable or disable the data labels.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
* description: The distance from the data label to the connector.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorpadding/ : No padding
* default: 5
*/
@property(nonatomic, readwrite) NSNumber *connectorPadding;
/**
* description: The background color or gradient for the data label. Defaults to undefined.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/ : Data labels box options
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
* description: Whether to http://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html : use HTML to render the labels.
* default: false
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
* description: When either the borderWidth or the backgroundColor is set, this		is the padding within the box.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/ : Data labels box options
* default: 5
*/
@property(nonatomic, readwrite) NSNumber *padding;
/**
* description: Styles for the label.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-style/ : Bold labels
* default: {"color": "contrast", "fontSize": "11px", "fontWeight": "bold", "textOutline": "1px 1px contrast" }
*/
@property(nonatomic, readwrite) NSDictionary /* <NSString, NSString> */ *style;
/**
* description: A http://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting : format string for the data label. Available variables are the same as for formatter.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-format/ : Add a unit
* default: {y}
*/
@property(nonatomic, readwrite) NSString *format;
/**
* description: The border radius in pixels for the data label.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/ : Data labels box options
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
* description: A class name for the data label. Particularly in http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, this can be used to give each series' or point's data label unique styling. In addition to this option, a default color class name is added so that we can give the labels a http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/data-label-contrast/ : contrast text shadow.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/series-datalabels/ : Styling by CSS.
*/
@property(nonatomic, readwrite) NSString *className;
/**
* description: The distance of the data label from the pie's edge. Negative numbers put the data label on top of the pie slices. Connectors are only shown for data labels outside the pie.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-distance/ : Data labels on top of the pie
* default: 30
*/
@property(nonatomic, readwrite) NSNumber *distance;
/**
* description: How to handle data labels that flow outside the plot area. The default is justify, which aligns them inside the plot area. For columns and bars, this means it will be moved inside the bar. To display data labels outside the plot area, set crop to false and overflow to "none".
* accepted values: ["justify", "none"]
* default: justify
*/
@property(nonatomic, readwrite) NSString *overflow;
/**
* description: The shadow of the box. Works best with borderWidth or backgroundColor. Since 2.3 the shadow can be an object configuration containing color, offsetX, offsetY, opacity and width.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/ : Data labels box options
* default: false
*/
@property(nonatomic, readwrite) id /* Bool, Object */ shadow;
/**
* description: The vertical alignment of a data label. Can be one of top, middle or bottom. The default value depends on the data, for instance in a column chart, the label is above positive values and below negative values.
* accepted values: ["top", "middle", "bottom"]
*/
@property(nonatomic, readwrite) NSString *verticalAlign;
/**
* description: The text color for the data labels. Defaults to null.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-color/ : Red data labels
*/
@property(nonatomic, readwrite) HIColor *color;
/**
* description: The Z index of the data labels. The default Z index puts it above the series. Use a Z index of 2 to display it behind the series.
* default: 6
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
* description: The border width in pixels for the data label.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/ : Data labels box options
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
* description: Callback JavaScript function to format the data label. Note that if a format is defined, the format takes precedence and the formatter is ignored. Available data are:


this.percentage
Stacked series and pies only. The point's percentage of the total.


this.point
The point object. The point name, if defined, is available 
through this.point.name.


this.series:
The series object. The series name is available 
through this.series.name.


this.total
Stacked series only. The total value at this point's x value.


this.x:
The x value.


this.y:
The y value.


*/
@property(nonatomic, readwrite) NSString /* Function */ *formatter;
/**
* description: The y position offset of the label relative to the point. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-rotation/ : Vertical and positioned
* default: -6
*/
@property(nonatomic, readwrite) NSNumber *y;
/**
* description: The x position offset of the label relative to the point. 
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-rotation/ : Vertical and positioned
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
* description: The color of the line connecting the data label to the pie slice. The default color is the same as the point's color.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the connector stroke is given in the .highcharts-data-label-connector class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorcolor/ : Blue connectors.

http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/pie-point/ : Styled connectors.
* default: {point.color}
*/
@property(nonatomic, readwrite) NSString *connectorColor;
/**
* description: Text rotation in degrees. Note that due to a more complex structure, backgrounds, borders and padding will be lost on a rotated data label.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-rotation/ : Vertical labels
* default: 0
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
* description: Whether to hide data labels that are outside the plot area. By default, the data label is moved inside the plot area according to the overflow option.
* default: true
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *crop;
/**
* description: The border color for the data label. Defaults to undefined.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/ : Data labels box options
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
* description: The width of the line connecting the data label to the pie slice.
In http://www.highcharts.com/docs/chart-design-and-style/style-by-css : styled mode, the connector stroke width is given in the .highcharts-data-label-connector class.
* demo: http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorwidth-disabled/ : Disable the connector.


http://jsfiddle.net/gh/get/jquery/3.1.1/highcharts/highcharts/tree/master/samples/highcharts/css/pie-point/ : Styled connectors.
* default: 1
*/
@property(nonatomic, readwrite) NSNumber *connectorWidth;

-(NSDictionary *)getParams;

@end
