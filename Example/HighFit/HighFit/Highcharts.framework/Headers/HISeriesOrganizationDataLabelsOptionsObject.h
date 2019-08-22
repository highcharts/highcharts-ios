/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIFunction.h"


/**
 */
@interface HISeriesOrganizationDataLabelsOptionsObject: HIChartsJSONSerializable

/**
A callback for defining the format for _nodes_ in the organization chart. The `nodeFormat` option takes precedence over `nodeFormatter`. In an organization chart, the `nodeFormatter` is a quite complex function of the available options, striving for a good default layout of cards with or without images. In organization chart, the data labels come with `useHTML` set to true, meaning they will be rendered as true HTML above the SVG.
*/
@property(nonatomic, readwrite) HIFunction *nodeFormatter;

-(NSDictionary *)getParams;

@end
