/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for the series data labels, appearing next to each data point. Since v6.2.0, multiple data labels can be applied to each single point by defining them as an array of configs. In styled mode, the data labels can be styled with the `.highcharts-data-label-box` and `.highcharts-data-label` class names.
*/
@interface HIPlotPieDataLabelsOptionsObject: HIChartsJSONSerializable

/**
Alignment method for data labels. Possible values are: - `toPlotEdges`: each label touches the nearest vertical edge of the plot area - `connectors`: connectors have the same x position and the widest label of each half (left & right) touches the nearest vertical edge of the plot area.
*/
@property(nonatomic, readwrite) NSString *alignTo;
/**
The color of the line connecting the data label to the pie slice. The default color is the same as the point's color. In styled mode, the connector stroke is given in the `.highcharts-data-label-connector` class.
*/
@property(nonatomic, readwrite) NSString *connectorColor;
/**
The distance from the data label to the connector. Note that data labels also have a default `padding`, so in order for the connector to touch the text, the `padding` must also be 0.
*/
@property(nonatomic, readwrite) NSNumber *connectorPadding;
/**
Specifies the method that is used to generate the connector path. Highcharts provides 3 built-in connector shapes: `'fixedOffset'` (default), `'straight'` and `'crookedLine'`. Using `'crookedLine'` has the most sense (in most of the cases) when `'alignTo'` is set. Users can provide their own method by passing a function instead of a String. 3 arguments are passed to the callback: - Object that holds the information about the coordinates of the label (`x` & `y` properties) and how the label is located in relation to the pie (`alignment` property). `alignment` can by one of the following: `'left'` (pie on the left side of the data label), `'right'` (pie on the right side of the data label) or `'center'` (data label overlaps the pie). - Object that holds the information about the position of the connector. Its `touchingSliceAt` porperty tells the position of the place where the connector touches the slice. - Data label options The function has to return an SVG path definition in array form (see the example).
*/
@property(nonatomic, readwrite) id connectorShape;
/**
The width of the line connecting the data label to the pie slice. In styled mode, the connector stroke width is given in the `.highcharts-data-label-connector` class.
*/
@property(nonatomic, readwrite) NSNumber *connectorWidth;
/**
Works only if `connectorShape` is `'crookedLine'`. It defines how far from the vertical plot edge the coonnector path should be crooked.
*/
@property(nonatomic, readwrite) NSString *crookDistance;
/**
The distance of the data label from the pie's edge. Negative numbers put the data label on top of the pie slices. Connectors are only shown for data labels outside the pie.
*/
@property(nonatomic, readwrite) NSNumber *distance;
/**
Whether to render the connector as a soft arc or a line with sharp break. Works only if `connectorShape` equals to `fixedOffset`.
*/
@property(nonatomic, readwrite) NSNumber *softConnector;

-(NSDictionary *)getParams;

@end
