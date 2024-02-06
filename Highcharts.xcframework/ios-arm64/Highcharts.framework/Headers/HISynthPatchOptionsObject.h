/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
A set of options for the SynthPatch class.
*/
@interface HISynthPatchOptionsObject: HIChartsJSONSerializable

/**
Master EQ filters for the synth, affecting the overall sound.
*/
@property(nonatomic, readwrite) NSArray *eq;
/**
Volume envelope for the overall attack of a note - what happens to the volume when a note first plays. If the volume goes to 0 in the attack envelope, the synth will not be able to play the note continuously/ sustained, and the notes will be staccato.
*/
@property(nonatomic, readwrite) NSArray<NSString *> *masterAttackEnvelope;
/**
Volume envelope for the overall release of a note - what happens to the volume when a note stops playing. If the release envelope starts at a higher volume than the attack envelope ends, the volume will first rise to that volume before falling when releasing a note. If the note is released while the attack envelope is still in effect, the attack envelope is interrupted, and the release envelope plays instead.
*/
@property(nonatomic, readwrite) NSArray<NSString *> *masterReleaseEnvelope;
/**
Global volume modifier for the synth. Defaults to 1. Note that if the total volume of all oscillators is too high, the browser's audio engine can distort.
*/
@property(nonatomic, readwrite) NSNumber *masterVolume;
/**
MIDI instrument ID for the synth. Used with MIDI export of Timelines to have tracks open with a similar instrument loaded when imported into other applications. Defaults to 1, "Acoustic Grand Piano".
*/
@property(nonatomic, readwrite) NSNumber *midiInstrument;
/**
Time in milliseconds to glide between notes. Causes a glissando effect.
*/
@property(nonatomic, readwrite) NSNumber *noteGlideDuration;
/**
Array of oscillators to add to the synth.
*/
@property(nonatomic, readwrite) NSArray *oscillators;

-(NSDictionary *)getParams;

@end
