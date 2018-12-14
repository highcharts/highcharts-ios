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
A config object for bindings in Stock Tools module.
*/
@interface HIStockToolsBindingsObject: HIChartsJSONSerializable

/**
ClassName of the element for a binding.
*/
@property(nonatomic, readwrite) NSString *className;
/**
Last event to be fired after last step event.
*/
@property(nonatomic, readwrite) HIFunction *end;
/**
Initial event, fired on a button click.
*/
@property(nonatomic, readwrite) HIFunction *initial;
/**
Event fired on first click on a chart.
*/
@property(nonatomic, readwrite) HIFunction *start;
/**
Last event to be fired after last step event. Array of step events to be called sequentially after each user click.
*/
@property(nonatomic, readwrite) NSArray<HIFunction *> *steps;

-(NSDictionary *)getParams;

@end
