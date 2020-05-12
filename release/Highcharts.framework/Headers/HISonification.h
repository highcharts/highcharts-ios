/**
* (c) 2009-2020 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Language options for sonification.
*/
@interface HISonification: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *playAsSoundClickAnnouncement;
@property(nonatomic, readwrite) NSString *playAsSoundButtonText;

-(NSDictionary *)getParams;

@end
