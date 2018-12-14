/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIRight.h"
#import "HIBottom.h"
#import "HITop.h"
#import "HIBack.h"
#import "HIFront.h"
#import "HILeft.h"


/**
Provides the option to draw a frame around the charts by defining a bottom, front and back panel.
*/
@interface HIFrame: HIChartsJSONSerializable

/**
The right of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HIRight *right;
/**
The bottom of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HIBottom *bottom;
/**
The top of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HITop *top;
/**
The back side of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HIBack *back;
/**
Whether the frames are visible.
*/
@property(nonatomic, readwrite) NSString *visible;
/**
The front of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HIFront *front;
/**
General pixel thickness for the frame faces.
*/
@property(nonatomic, readwrite) NSNumber *size;
/**
The left side of the frame around a 3D chart.
*/
@property(nonatomic, readwrite) HILeft *left;

-(NSDictionary *)getParams;

@end
