/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIColor.h"
#import "HICSSObject.h"


/**
An object of key-value pairs for SVG attributes. Attributes in Highcharts elements for the most parts correspond to SVG, but some are specific to Highcharts, like `zIndex`, `rotation`, `rotationOriginX`, `rotationOriginY`, `translateX`, `translateY`, `scaleX` and `scaleY`. SVG attributes containing a hyphen are _not_ camel-cased, they should be quoted to preserve the hyphen.
*/
@interface HISVGAttributes: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSArray /* <NSNumber, NSString> */ *d;
@property(nonatomic, readwrite) HIColor *fill;
@property(nonatomic, readwrite) NSNumber /* Bool */ *inverted;
@property(nonatomic, readwrite) NSArray<NSNumber *> *matrix;
@property(nonatomic, readwrite) NSNumber *rotation;
@property(nonatomic, readwrite) NSNumber *rotationOriginX;
@property(nonatomic, readwrite) NSNumber *rotationOriginY;
@property(nonatomic, readwrite) NSNumber *scaleX;
@property(nonatomic, readwrite) NSNumber *scaleY;
@property(nonatomic, readwrite) HIColor *stroke;
@property(nonatomic, readwrite) HICSSObject *style;
@property(nonatomic, readwrite) NSNumber *translateX;
@property(nonatomic, readwrite) NSNumber *translateY;
@property(nonatomic, readwrite) NSNumber *zIndex;

-(NSDictionary *)getParams;

@end
