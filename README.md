# SickoCV v2.5.5-beta2
VCV Rack plugin modules (BETA TEST AREA)  
Compile or **download binary for ANY platform** on the releases page  

## IMPORTANT INSTALLATION NOTE
If you don't use VCV development environment and run regular VCV install,  
the new modules will be shown up only if you have a **full subscription** to Sickozell plugin modules.  

So if you have added only some Sickozell modules to VCV you will not see the new ones.

Please check your subscription on https://library.vcvrack.com/plugins and look for the SickoCV line that has to be like this:  
![subscription](https://user-images.githubusercontent.com/80784296/207971796-96163a4b-6fa9-4073-bda8-9df1e61f900b.JPG)

## Current modules in beta testing:
- all **Player/Sampler** modules

## **to do list:** 
- modules test

## **changelog**  
- fixed a bug on all player/sampler modules crashing VCV on MACs when root folder is not found
- added a functionality on all player/sampler modules to to show the path of not found files

# SickoCV v2.5.5
VCV Rack plugin modules

![SickoCV modules 2 5 4](https://github.com/sickozell/SickoCV/assets/80784296/0240477b-b56a-4375-a31d-3c0a2f668bde)

## Common modules behavior
- Triggers and gates threshold is +1v
- Every time-related knob set full anticlockwise and displaying 1ms on the tooltip is actually considered 0ms

## Adder8
### 8 Adder and subtractor
#### - DESCRIPTION
'adder8' is inspired by hardware precision adder modules. It adds, ignore or subtracts fixed voltages or CVS to outputs. 

![adder8](https://github.com/sickozell/SickoCV/assets/80784296/b3d1e618-fcc4-49c1-8662-7ddf119e7304)

#### - INSTRUCTIONS
On the first row a fixed voltage set by VLT/ATNV knob is added, ignored or subtracted, depending on the -0+ switch, to the corresponding output.  
If the output is not connected, the result voltage is summed to the next row, and with the same rules until a connected output is found.  
If a CV input is connected, the VLT/ATNV knob acts as an attenuverter, then the CV voltage will be added or subtracted in the same previous way.  
When an output is connected, the starting voltage of the next row is reset to 0v just like the first row does.  
The MODE switches force the "-0+" switches to be as: "subtract/ignore", "subtract/ignore/add" or "ignore/add".  

#### CONTEXT MENU
- **Stop Adding on Out Cable** (ticked by default). As mentioned above, the starting voltage is reset to 0v in the next row only when an out cable is detected. Unticking this option the voltage won't be reset.
- **Volt Knob Default**. With this option the default initialization value of the VLT/ATNV knob can be changed to 0v, +1v or +10v.  
This unconventional feature lets the user to choose the default knob value depending on the main usage of Adder8:  
if it's used as a fixed pitch adder (without input CV connection) maybe it's useful to have the default value set to +1v, so if the knob position has been changed to detune, it can be quickly restored to add (or subtract) exactly 1 octave in pitch;  
otherwise, if the knob is used as attenuverter with a CV input connected, it can be set to 0v as usual or to +10v to quickly get the full CV voltage.
- **Reset All Knobs to Default**. This resets all knobs value to selected default setting.

## Blender
### Polyphonic stereo crossfade mixer with double modulation
#### - DESCRIPTION
'blender' is a crossfade mixer of mono or stereo signals.  
It can be used either with cv signals or audio sources.  
Mix can be modulated by uni/bipolar signals.  
Modulation can be further modulated by another signal.  
Audio rate modulations are allowed.

![blender](https://user-images.githubusercontent.com/80784296/211660967-ce9aa25d-cc8f-45a9-beae-3381a13cf0af.JPG)

#### - INSTRUCTIONS
Connect CVs or audio sources to IN1 and IN2, mono or stereo signals can be independently used. Polyphonic inputs are allowed and are left/right independent, but accordingly to number of channels of IN1 input.  
PHASE switches invert the sign of input signals.  
MIX knob sets the crossfade level of the inputs.  
Inputs volume can be adjusted via two attenuators.  
Master volume can be amplified up to 200%, a hard clip ±5v switch is present.  
Output replicates input polyphony, but deticking in the context menu 'Polyphonic outs' option will mix channels into monophonic outs.

**MOD section**  
Connecting MIX MOD CV input enables mix modulation. ATNV knob attenuverts CV input.  
CV input range is usually unipolar 0-10v. RNG switch in 'bipolar' position adds +5v to CV input, so audio signals can be used for modulation.    
Modulation is added to the MIX knob.

**MOD2 section**  
MOD2 can be used to add modulation to the MOD attenuverter knob in MOD section, the rules are the same.

## Blender8
### 8 single crossfade mixers with modulation
#### - DESCRIPTION
'blender8' is a set of 8 crossfade mixers of two signals.  
As the previous one it can be used either with cv signals or audio sources.  
Mix can be modulated by uni/bipolar signals.  
Audio rate modulations are allowed.

![blender8](https://user-images.githubusercontent.com/80784296/201516772-12dac17b-f8a0-4f82-946a-da8b7d254b09.JPG)

#### - INSTRUCTIONS
'blender8' provides 8 mono crossfade mixers and differs from 'blender' module in the following things.  
Only the IN2 input signal can be phase inverted.  
If a CV input is connected for modulation, CV sets the mix percentage and the MIX knob becomes the CV attenuverter.

## bToggler / bToggler Compact
### Buffered stereo signal toggle switch router, with VCA and ASR envelope generator, in regular and compact form factor
#### - DESCRIPTION
- Buffered Toggled VCA with builtin ASR envelope generator
- Buffered Toggled ASR envelope generator
- Buffer mute/unmute CVs or mono/stereo AUDIO signals according to an ASR envelope activated by Toggle Triggers

![btoggler](https://user-images.githubusercontent.com/80784296/211221913-2ac04d94-b80b-4222-a02b-2719e0fb4d38.JPG)

#### - INSTRUCTIONS
Connect a clock source.

When ARM input is triggered (arm on), the L+(R) inputs will start to be routed to L+(R) outputs on next clock detection (according to ASR envelope values) and GATE output will provide a high state.

Then, with another ARM triggering (arm off) the routing will stop on next clock detection and GATE output will go low.

If ARM is triggered again before clock detection it will abort arming (unarm).

Attack, Sustain and Release knobs set the envelope of the routed signals.

A, S, R CVinputs are added to respective knob values, bToggler module has attenuverters.

If L or (R) inputs are not connected, relative outputs will provide just the envelope, so a mono signal can be connected to L input to route it to L output and nothing connected to (R) input to have the envelope on (R) output.

A trigger on RESET input will reset the toggle state.

Polyphony on L/(R) inputs is replicated on outs.   

#### Context Menu
- Initialize On Start: discards previous module state on VCV restart
- Disable Unarm: this disables unarm feature

## bToggler8
### 8 buffered toggle switch signal router
#### - DESCRIPTION
'bToggler8' can be used to mute/unmute up to 8 CVs or AUDIO signals, in sync to a tempo clock source.  
For example it can be used to play/stop drumkit parts independently (kick, snare, hats, etc):
- connect an appropriate clock source to CLOCK 
- connect the ARMs to a "MIDI>GATE" module which receives controls from a midi controller
- connect the INs to the sequencer outs, one for kick, one for snare, etc.
- connect the OUTs to the trigger inputs of the single drum modules

Then, by pressing buttons on the controller, 'bToggler8' will actually start/stop the single drum parts on the next received clock pulse.

Otherwise bToggler OUTs can be connected to envelope generators. In that case the GATE output should be connected to the IN input to activate the envelope.

'bToggler8' can also be used to route audio signals. Connect IN to the audio source and OUT to the mixer: the FADE knob will avoid clicks.

![btoggler8](https://user-images.githubusercontent.com/80784296/233732638-2cee94ff-f323-43d9-9e04-b99dbe833daf.JPG)

#### - INSTRUCTIONS
Connect a clock source.

When ARM input is triggered (arm on) the IN input will start to be routed to OUT on next clock detection and GATE output will provide a high state.

Then, with another ARM triggering (arm off) the routing will stop on next clock detection and GATE output will go low.

FADE knob up to 10s can be used to avoid attack or release clicks when audio signals are connected to IN input.  
Be sure to set Fade knob to minimum (1ms) when inputs are feeded by triggers.  

If ARM is triggered again before clock detection it will abort arming (unarm).

Triggering RESET input will immediately stop the routing.

Triggering RESETALL input will immediately stop all the 8 routings.

#### **Context Menu**
- Initialize On Start: discards previous module state on VCV restart
- Disable Unarm: this disables unarm feature
 
Here below is one example of bToggler8 usage. When buttons are pressed on PULSES module, incoming triggers from the sequencer are routed to drum modules only when the first step of the sequencer is reached. If buttons are pressed again, the routing will stop on next first step of the sequencer.

![bToggler8 example](https://user-images.githubusercontent.com/80784296/204083532-db145211-1f61-45cd-9c4d-572fc243d7d3.JPG)  
[Download example](./examples/bToggler8%20example.vcvs?raw=true) (right-click -> save link as)

## bToggler8+
### 8 buffered toggle switch router, plus warnings to use with led midi controllers
#### - DESCRIPTION
'bToggler8+' is almost the same of the previous one, but it has a further feature (WRN outs) to be used with programmable led midi controllers to have a visual feedback on the controller.

Some midi controllers can light up or turn off their button leds by receiving the same commands they send.  
Taking advantage of this functionality, connect the WRN outs to a "GATE>MIDI" module connected to the same controller of the ARM inputs.  
So when pressing buttons on controller, 'bToggler8+' will actually play/stop the sequencers or audio, and simultaneously give a visual feedback on the controller.

![btoggler8plus](https://user-images.githubusercontent.com/80784296/233729070-514762a0-d978-4d03-9ac5-62dab9ef1078.JPG)

#### - INSTRUCTIONS
The same of the previous one, plus following features.

When 'armed on' or 'armed off', the WRN (warning) output will provide a sequence of pulses until next clock is detected.  
Then it will act as the OUT output (the routed signal) if the FADE knob is set to 1ms, else it will act as the GATE output (high gate).  
So, if 'bToggler8+' is receiving triggers from a sequencer, the FADE knob will be set to 1ms and the led will light up the same as sequencers trigs.  
Otherwise, if fade knob is set different from 1ms, it is supposed that an audio signal is routed, so a fixed led light on the controller will be seen.

WA and WR knobs set the attack (arm on) and release (arm off) pulserate up to 200 ms of the warning pulses. These are two independent settings because it can be helpful to notice if the routing is going to start or stop.

If WA or WR are set to 0ms, WRN will output a low gate during warning time and if set to to max (200ms) it will output a high gate.  
As to say: if WA is set to 0 and WR is set to max(200), WRN output will act like the GATE output.  
Otherwise if WA is set to max(200) and WR is set to 0, WRN output will act as simple toggle switch with no buffer feature.

#### Context Menu
- Initialize On Start: discards previous module state on VCV restart
- Disable Unarm: this disables unarm feature
- WRN Inversion (trigs only): inverts WRN output behavior when used with triggers. It can be useful when INs are feeded by sequencers trigs and WRN Outs connected to a led midi controller. With this option enabled when there's no routing leds will stay off, when routing leds will stay on and whenn a trig is received led will be turned off for 100ms.

Here below is one example of bToggler+ usage. The MIDI>GATE module is connected to a programmable Led Midi controller and receives buttonpresses from it. The GATE>MIDI module send back triggers incoming from the sequencer to the controller, turning on and off the corresponding led buttons only when triggers are actually routed to drum modules. Routing rules are the same of previous example.

![bToggler8plus example](https://user-images.githubusercontent.com/80784296/204083544-34ecf3b0-0d12-4965-bd72-f3bb85339551.JPG)  
[Download example](./examples/bToggler8plus%20example.vcvs?raw=true) (right-click -> save link as)

## Calcs
### Calculates sums, differences, multiplications, divisions and averages of 3 CV inputs

![calcs](https://user-images.githubusercontent.com/80784296/233733100-719eb0c9-e6c1-467c-a2c6-cfe8b02012fb.JPG)

#### - INSTRUCTIONS
A, B and C are the inputs. The output tables provide simple math calculations and averages between two inputs or the average of all of them.

U/B (Unipolar/Bipolar) switch clamps the outputs to 0/10V or ±5v.

## Clocker
### Clock generator with 4 dividers/multipliers and audio metronome

#### - DESCRIPTION
Clocker is a high precision clock generator and modulator with 4 dividers/multipliers and integrated audio click.

![clocker](https://github.com/sickozell/SickoCV/assets/80784296/7cdfce27-6f65-4a45-ad29-4c62aefa22d8)

#### - INSTRUCTIONS
The BPM knob sets the clock speed from 30 to 300 bpm.  
An external clock can be connected on the EXT input.  
The RUN button or a trig on its input starts or stops the clock.  
PW (pulse width) knob adjusts the length of the gate in its high state.  
Clock and metronome can be reset with RST button or a trig on its input.  

There are 4 clock dividers/multipliers up to 256x each with theirs PW control. Right click on the display to quick select the desired division/multiplication.  

The metronome setting is controlled by the METER knob or with a right click on the display.  
Audio click is activated with CLICK button and volume can be adjusted with the knob from 0 to 200%.  
BEAT and BAR outputs are always active and give a 1ms trigger.

#### Context Menu

- **Click Presets**  
There are 3 predefined types of audio clicks, each one with beat and bar sample.  

- **Load BEAT click / Load BAR click**  
Audio clicks can be customized loading wav sample using "Load BEAT" and "Load BAR" options.  

- **Beat pulses also on Bar**  
When ticked, BAR pulses on the BAR output are duplicated on the BEAT output.  

- **On Run**  
"Beat Reset" resets metronome when the Run Button is switched on.  
"Reset Pulse" sends a reset pulse on Reset output when the Run Button is switched on.

- **On Stop**  
This submenu is the same as the previous one but when the Run Button is switched off.

## CvRouter CvSwitcher
### 1>2 and 2>1 voltage controlled switch  

![cvRouter cvSwitcher](https://github.com/sickozell/SickoCV/assets/80784296/d82e6cda-d973-4476-8d3a-28640a4bbe41)

#### - INSTRUCTIONS
With the cvRouter the IN signal will be routed to OUT1 or OUT2 if the CV input voltage is lower or higher than the voltage set by the "THR" threshold knob.  
With the cvSwitcher the OUT will receive the signal from IN1 or IN2 if the voltage of the CV input is lower or higher than the voltage set by the threshold "THR" knob.

The FADE knob with its added CV input, will crossfade up to 10s the INs or OUTs. 

The default value of the "THR" knob is +1v.

## Drummer Drummer4 Drummer4+
### Accent and choke utility for drum modules lacking these features

![drummer](https://user-images.githubusercontent.com/80784296/212536993-c8ac8011-b324-4dae-99f6-8f8b548557eb.JPG)

#### - INSTRUCTIONS
Drummer and Drummer4/Drummer4+ module can handle 2 or 4 drum sounds with separate standard and accent volume levels set by respective knobs.  

Connect the IN input to a drum-like audio source or sample player, and OUT output to the mixer.  
Connect the TRIG input to the same module that feeds the drum module, it can be a sequencer or every other pulse generation module.  
Connect the ACC input to the module which generates the accents, it can be the sequencer or every other suitable module.  
When ACC is triggered at the same time as the TRIG input, Drummer module will output the Accent Level set by "Accent Level knob" instead of the one set by "Standard Level Knob".  

Each knob range is from 0 to 200% of the incoming IN level.  
LIMIT switch hard clips the output in the range ±5v.  
When CHOKE switch is on and a trigger occurs, the other slot (Drummer) or the next slot (Drummer4) is muted (for example when used with closed/open hihat sounds).  

- **Drummer note:**  
If 1 OUT is not connected, the audio signal will be mixed with the other one connected.  
In CHOKE mode, if both TRIG inputs are triggered at the same time, the upper section (#1) will have the priority and the lower one will be ignored.

Example of Drummer module usage:

![drummer example](https://user-images.githubusercontent.com/80784296/212531420-150a0d94-12c6-463e-b46b-0828f5d45895.JPG)  
[Download example](./examples/drummer%20example.vcvs?raw=true) (right-click -> save link as)

- **Drummer4 note:**  
If one slot OUT is not connected, the audio signal will be added to the next one. For example if connecting only out #2 and #4, out #1 and #3 will be respectively mixed with those ones, if connecting only out #4, this socket will output all the channels.

Example of Drummer4 module usage:

![drummer4 example](https://user-images.githubusercontent.com/80784296/212531441-575f9b49-dee2-47ca-a82d-0861a10145e5.JPG)  
[Download example](./examples/drummer4%20example.vcvs?raw=true) (right-click -> save link as)

- **Drummer4+ note:**  
Drummer4+ it's the same of Drummer4. It only adds attenuverted CV inputs to parameter knobs.

## DrumPlayer DrumPlayer+ DrumPlayerXtra
### 4 channel Drum Sample Player with accent and choke functionality

![drumplayer](https://user-images.githubusercontent.com/80784296/221338110-d550144f-4e34-475d-9b00-00872910f331.JPG)

#### INSTRUCTIONS  
Load wav samples in the slots using general or slot context menu.  

When TRIG input is triggered the sample will be played at the volume percentage set by to "Standard Level" knob + its relative attenuverted CVinput.  
If ACCENT input is HIGH when TRIG occurs, the sample will be played at "Accent Level" knob + its attenuverted CVinput.  

Playing speed can be set by SPD knob from 1 to 200% and modulated with its attenuverted CVinput. Speed can be modified during sample playback.  
External modulation is allowed only on drumPlayer+ or drumPlayerXtra.  

If CHOKE switch is on when TRIG occurs, the playback of next slot is stopped with a 1ms fade out: it's commonly used to simulate a closed/open hihat.  
LIM switch enables hard clipping limiter set to ±5v on the output.  

#### CONTEXT MENU
**Sample Slots**  
Click on the slot number to open dialog.  
When the sample is loaded the green led on the panel is turned on (drumPlayer), or the small 7segment display will show the first chars of the filename (drumPlayer+ drumPlayerXtra).  


**Set samples root folder**  
Once a folder is set, 'Samples browser' option is activated in the quick load menu (right click in the relative led slot area/display) to quickly choose samples from the selected folder.  

**Interpolation**  
There are 3 different interpolation algorithms, that are engaged during playback only when the sample samplerate differs from VCV working samplerate or playback speed differs from 100%.  
- 'No interpolation' can be used when sample rates match and speed is 100% constant  
- 'Linear 1' and 'Linear 2' interpolate the samples with different weighted averages  
- 'Hermite' uses a Cubic Hermite interpolation that offers a better result (default)  

**Anti-aliasing filter**  
Anti-aliasing filter is made up with 2x oversampling and a 20khz lowpass filter.  

**Outs mode**  
Normalled (default): if one out is not connected, the output of its slot is added to the next one  
Solo: every slot has its own out socket  
Unconnected on Out 4: Every unconnected out is added to out n.4

**Disable NAV buttons** (drumPlayerXtra only)  
Disables panel Sample Navigation buttons to avoid utilizing mistakes.

**Scrolling Sample Names** (drumPlayer+ and drumPlayerXtra only)  
This option enables text scrolling on sample name displays  

**Light Boxes** (drumPlayerXtra only)  
This option enables a light box over waveform displays when sample is triggered.  
When enebled, in each slot context menu, the color of light and fade duration can be set.

**Display Triggering** (drumPlayerXtra only)  
This option enables sample triggering by clicking over the the display area, to play samples live or just to test them while navigating sample folders  

**Global Settings** (drumPlayerXtra only)  
In this menu there are options to clear all the slots or the root folder.  
It is also used to apply settings to all the slots: Zoom, Lightboxes color and time fading.   

#### SLOT CONTEXT MENU
Right clicking on led area (drumPlayer) or display area (drumPlayer+ drumPlayerXtra) the slot context menu is open with following options:  
- Load Sample (opens file dialog to load a sample in the slot)
- Samples Browser (if a root sample folder is set on the general context menu, this submenu is enabled to navigate through directories)
- Current sample (shows sample name when a sample is loaded)
- Clear (clears slot)
- Swap Slot with (swaps slot sample with the selected one)
- Copy Slot to (duplicates slot sample to the selected one)  

**drumPlayerXtra** further options:
- Zoom Waveform (zooms the waveform from start to end (full), half, quarter, eighth of the sample length)
- Light Box color (if Light Boxes option is enabled in the general context menu, a predefined color or a custom one can be set here)
- Light Box Fade (Fade time of Light Boxes is set here: Slow (0.5s), Normal (0.25s), Fast (0.1s)

## Parking
### Set of unconnected inputs and outputs just to park unused cables

![parking](https://user-images.githubusercontent.com/80784296/233734644-cc9eed31-a959-4ba3-b544-48ed16a6285b.JPG)

#### - INSTRUCTIONS
This module doesn't do anything. It's just a place to connect temporarily unused cables to not forget to where they were wired.  
It can also be used to connect other modules sockets when they need to be wired to obtain some functionality.

## Shifter
### 64 selectable stages shift register
#### - DESCRIPTION
- 64 stages shift register that outputs only the selected stage controlled by knob/CV with attenuverter
- Trigger delay to adjust the 1-sample latency of VCV cables

![shifter](https://user-images.githubusercontent.com/80784296/212537155-aceff24b-4dc8-4c04-9063-fad4543c9cd6.JPG)

#### - INSTRUCTIONS
Shifter module can be useful to shift back and fotrth a sequencer output on the fly, thanks to the 64 stages register.  
Stage can be controlled via the stage knob, or the 0-10v StageCV input with its attenuverter.  
If StageCV input is not connected, the attenuverter reduces the range of the Stage knob.  
Note that the Stage knob and StageCV are added together.  
The TRIG DELAY knob can be used to delay the TRIG INPUT up to 5 samples, because of the 1sample latency of VCV cables. This can be useful when triggering the sequencer with the same clock of Shifter module, TRIG DELAY avoids that the input is sampled before the sequencer advances.  

#### Context Menu
- Initialize On Start: discards previous module state on VCV restart

![shifter example](https://user-images.githubusercontent.com/80784296/212531455-776e3110-78ef-4bec-a3f8-64180fe4ca53.JPG)  
[Download example](./examples/shifter%20example.vcvs?raw=true) (right-click -> save link as)

## SickoPlayer
### wav sample player

#### - DESCRIPTION
- samples and 1-cycle waveforms player
- ±24 semitones tuning and v/oct input with polyphony
- envelope generator, loop, reverse, pingpong
- different interpolation modes, anti-aliasing filter, phase-scan feature

![sickoplayer](https://user-images.githubusercontent.com/80784296/233733849-2ccd0fb3-a556-4785-ad42-b952642ccd11.JPG)

#### - INSTRUCTIONS
Load sample using context menu or right-click in the waveform display area to access quick load menu.  
Once a sample is loaded samples in the same folder can be browsed using Previous and Next buttons above the display.  

The display shows the waveform, filename, sample duration and number of channels (1-2 channels wav file are allowed).  

Mode switch allows to select if sample playback starts with a trigger or play it until a gate is high.  

When in Trig Mode the Trig-Type switch has 3 options:  
- **SS (Start/Stop)** A trigger starts attack stage from CueStart postition, another trigger sets playback to release stage and at the end sample position is reset to cue start  
- **R (Restart)** Every trigger starts attack stage from CueStart position. Only a Stop trigger stops playback.  
- **PP (Play/Pause)** A trigger starts attack stage from curent sample position, another trigger goes to release stage. A Stop trigger reset position to CueStart.  

In any Trig-Type a trigger on STOP input sets the playback to release stage.

TRG/GTE and STOP buttons have effects only on channel 0 of polyphony.  

Cue Start/End knobs are used to set the start of the Attack and the Release stage.

When Loop button is switched on, playback restarts from Loop Start when Loop End is reached.

REV button changes the playback start direction.

PNG button enables PingPong mode:
- in TRIG mode, when loop is enabled, if Loop Start/End is reached playback direction is inverted without stopping playback
- in GATE mode, if Loop Start/End is reached when loop is enabled, or when Cue Start/End is reached, playback direction is inverted without stopping playback

XFD knob (crossfade) sets crossfading time in loop mode, or fadeout time before the end of sample is reached.  

The envelope knobs can be external modulated with attenuverted CVinputs.

Tune knob with its attenuverted CVinput, can tune up or down the sample with a ±2 octave range (semitone scale).  
v/oct input accepts polyphonic cable usually combined with a polyphonic gate in when in Gate Mode.  

Master knob, with its attenuverted CVinput, sets the output volume from 0 to 200%. Limit switch is a hard clip limiter with a ±5v range. A led clip light warns of clipping.  

If sample file is mono, left out is duplicated to right out.  
EOC outputs a 1ms pulse when the sample reaches certain point according to a specific context menu (see below).  
EOR outputs a 1ms pulse when the sample reaches the end of release stage.

#### CONTEXT MENU
**Sample Slot**  
Click on "Load Sample" to open dialog. Use Clear options to unload sample from slot.  
As described before, just right-click over the waveform display area to access the quick-load menu.  
When a sample is loaded, file sample rate and number of channels are shown here.  

**Set samples root folder**  
Once a folder is set, 'Samples browser' option is activated here and in the quick load menu (right click on display) to quickly choose samples from the selected folder and subfolders.    

**Interpolation**  
There are 3 different interpolation algorithms that are engaged during playback only when the sample samplerate differs from VCV working samplerate or playback speed differs from 100%.  
- 'No interpolation' can be used when sample rates match and tune is set to zero  
- 'Linear 1' and 'Linear 2' interpolate the samples with different weighted averages  
- 'Hermite' uses a Cubic Hermite interpolation that usually offers a better result (default)  

**Phase scan**  
This feature automatically sets Cue and Loop Start/Stop positions at zero crossing points to avoid loop clicks and pops eventually in combination with proper crossfade length.  
Be sure to disable it when using one-cycle waveforms, or simply use the specific preset (see below)  
Please not that Scan will be applied only on left channel  

**Anti-aliasing filter**  
Anti-aliasing filter is made up with 2x oversampling and a 20khz lowpass filter.  

**Polyphonic OUTs**  
When this option is enabled the audio and EOC/EOR outputs reflect v/oct input polyphony. Otherwise polyphonic outputs are mixed in one monophonic out.

**Polyphonic Master INs**  
When this option is enabled the Master CV input accepts polyphonic cables according to V/Oct input polyphony. For example this can be used for velocity control.

**EOC pulse from**  
This submenu sets when the EOC pulses are triggered:  
- TRG/GATE when is triggered to stop
- STOP triggering
- reached CUE END (on forward playback)
- reached CUE START (on reverse playback)
- reached LOOP END (on forward playback)
- reached LOOP START (on reverse playback)
- PING: reached LOOP END (when pingpong looping on forward playback)
- PONG: reached LOOP START (when pingpong looping on reverse playback)

**Disable NAV buttons**
Disables panel Sample Navigation buttons to avoid utilizing mistakes.

**Reset Cursors**  
Resets Cue/Loop Start/stop to 0 and 100%.  

**Reset Cursors on Load**  
Always resets Cue/Loop Start/stop to 0 and 100% when a new sample is loaded.  

**Presets**
There are some factory presets stored in the context menu for common using settings.  

#### USING ONE-CYCLE WAVEFORMS
One-cycle waveforms can be used in GATE mode with LOOP mode enabled.  
Be sure to recall relative preset or disable PhaseScan, adjust Cue and Loop START to 0% and Cue/Loop END to 100% and enable loop button.  

## SickoSampler
### wav sample player and recorder

#### - DESCRIPTION
- mono/stereo sample recorder  
- mono/stereo samples and 1-cycle waveforms player
- ±24 semitones tuning and v/oct input with polyphony
- envelope generator, loop, reverse, pingpong
- anti-aliasing filter, phase-scan feature

![sickosampler](https://github.com/sickozell/SickoCV/assets/80784296/48c9dee5-1ae1-49c2-8ffd-e43b6f2de9fa)

#### - INSTRUCTIONS

About player functionalities please follow sickoPlayer instructions. Please note that loaded samples in sickoSampler are always resampled to VCV working samplerate. For this reason interpolation is fixed to Hermite. It can be always toggled antialiasing filter from context menu. 

In sickoSampler the display shows also the recording time and a yellow "S" if sample is not saved yet. 
In the context menu, along file infos, it's shown if the sample was resampled on loading and if it has to be saved because a recording occurred.  

Recording section has 2 inputs, but record is only enabled if at least left channel is connected.  
Record button arms recording waiting for a playback trig, or starts recording when a sample is playing back, or starts recording immediately if PoR button is on (see below).   
Record trig input toggles start/stop or arm/unarm recording, but if "STOP REC" trig input is connected it only starts recording.  

GAIN knob adjusts the volume of the inputs.  
FD knob sets the fade in/out time when recording starts or stops.  

OVD button overdubs existing sample.  

XTN button enables extended recording. In forward recording, it continues recording also when cue end point or sample end are reached. In reverse recording it keeps recording until sample begin point is reached. If loop is enabled XTN button has no effect and it will record as usual.  
Please note that when in loop recording XFD knob is overridden, and it will not do any crossfade.  

RRM (REC Re-Arm): when recording is stopped by a playback trig/button, it is rearmed when release time has ended or fadeout recording has finished. This function is not available in conjunction with POR "Play on REC". In "Restart" trig-type mode recording is rearmed only when after a STOP trig/button is detected.  

REL (Record Release Stage): keeps recording while playback is stopped and it is in its release stage. Please note that it will always continue recording until the "Rec Fade in/out" knob (FD) time setting is reached (also if release stage of the playback is reached).  

UCE (Update Cue End): resets the Cue End cursor to the end of recording when it is stopped (if recording is reversed it updates Cue Start cursor).

ULE (Update Loop End): same as above, but affects Loop End cursor.

POR (Play On REC ON): when REC button is switched ON or REC trig it will start playback and recording simultaneously. It disables also the REC Re-Arm function.  

SOR (Stop On REC OFF): when REC button is switched OFF or REC trig or REC STOP trig, it will stop record and playback simultaneously. If playback STOP button/trig occurs, it will stop recording only and continue playing. In Play/Pause trig type it will reset position to Cue Start as STOP button/trigger usually does.   

MON switch selects inputs routing to the outs: always [ON], while recording only [REC], or never [OFF].  

Recording speed follows v/oct and tune settings.  
As recording is not polyphonic, polyphony is disabled when the REC button is switched on, and the record playhead will follow only channel nr 0 on the polyphonic cables connected to v/oct.  

**HINT**: If it's planned to record a sample to play it polyphonically with a master keyboard, please connect gate and v/oct to a MIDI>CV module with 'Reset' polyphony mode selected. Clear any previous sample in memory, select GATE mode, switch the LOOP button on, arm recording and consider adjusting envelope knobs. On key press (C4 for example) sickoSampler will start recording until key is unpressed, then the sample can be played immediately.

**New sample recording**  
In Trig Mode, when recording is stopped by a trig or blue button press and LOOP button is switched on, the sample will be played back immediately in loop mode, and if Rec Re-Arm is on it will keep recording.


#### CONTEXT MENU
Please refer to sickoPlayer for context menu, in sickoSampler following options are added:
- Save FULL Sample: saves the entire sample in a wav file.
- Save CUE Region: saves the wav file from Cue Start to Cue End
- Save LOOP Region: saves the wav file from Loop Start to Loop End
- Trim Sample after Save: If this option is enabled, the sample is trimmed and saved in the chosen saving mode, otherwise it will be saved trimmed, but the entire sample remains available in memory
- Save Oversampled: If this option is enabled, samples will be saved at sickoSampler working samplerate (2x VCV samplerate). This can be useful when samples are recorded at different speeds than normal for further external editing.
- UCE/ULE updates also Start: if UCE and/or ULE button are on, when recording is stopped also Cue Start and/or Loop Start cursors are reset to the recording start position (if recording is reversed it updates Cue/Loop End cursor).
- Crossfade while Rec Fading: If overdub is not activated this option crossfades between previous and current recording only during fading in/out recording time, accordingly to the FD knob.

## Switcher / SwitcherSt
### 2>1 switch, 1>2 router, 2 signal swapper, mute, flip flop, toggle gate
#### - DESCRIPTION
- Signal switch (2 inputs, 1 output)
- Signal router (1 input, 2 outputs)
- Signal swapper (2 inputs, 2 outputs)
- Mute (1 input, 1 output)
- Flip flop
- Toggle gate
- Function type autodetection (switch, route, swap, mute, flipflop, toggle gate)
- Adjustable time crossfade between switched/routed/swapped signals

![switcher](https://user-images.githubusercontent.com/80784296/201516861-d3d2ab1b-7036-4355-b2ef-e4c5681fb432.JPG)

#### - INSTRUCTIONS
Switcher or SwitcherSt (used for stereo signals) are multifunction modules that can be used as follows. The versatility of the module is offered thanks to the automatic detection of the function type.

**TOGGLE/GATE modes**  
When the MODE switch is in 'TOGGLE' position functions are activated by triggers in a toggle style.  
When in 'GATE' position functions are gate sensitive, so they stay active until 'T/G' input receives a high gate.  

**Function types**  
The function type is automatically detected depending on connected cables.  

Switch: connect 2 inputs and 1 output  
Router: connect 1 input and 2 outputs  
Swapper: connect both two inputs and two outputs  
Mute: connect 1 input and 1 output  
FlipFlop: connect 2 outputs only  
ToggleGate: connect 1 output only ('TOGGLE' mode only)  

A trigger on RST input will reset the toggle to its default state.  

**Defaults**  
Default states depend on function type and which input or output sockets are connected.  

Switch: if OUT1 is connected, the default signal will be the IN1 input. If OUT2 is connected instead, the default signal will be the IN2 input  
Router: if IN1 is connected, the signal will be routed to OUT1 output by default. If IN2 is connected, the default destination will be OUT2 output  
Swapper: the default is always IN1>OUT1 and IN2>OUT2. 
Mute: if IN1 and OUT1 (or IN2 and OUT2) the defualt is mute. If IN1 and OUT2 (or IN2 and OUT1) are connected the default is signal unmute  
FlipFlop: default is always OUT1  
ToggleGate: if OUT1 is connected the default is a LOW GATE. If OUT2 is connected instead, the default is a HIGH GATE  

**Leds**  
Green leds close to the in/out sockets show which input signal is switched or to which output destination is routed.  
When used as a swapper the OUT1 led on shows that signals are normally routed, otherwise the OUT2 led on shows when signals are swapped.  

**Fader**  
Fader knob sets the crossfade time (up to 10s) between the switched/routed/swapped signals. Set the knob to minimum (1ms) to have no fade.
CV input is added to Fade knob value and the sum will be clamped in the range of 0-10v.  

#### Context Menu
- Initialize On Start: discards previous module state on VCV restart

**NOTES**  
- If Fader knob is set to 1ms it won't do any fade
- In FlipFlop and ToggleGate function types the output will consist in a 'fixed' AR envelope
- When a fade time is set, the module will act as an envelope generator, so if a function activation is detected during a fade, the function will restart immediately (not like a function generator)
- On SwitcherSt module the function type is detected on Left channel sockets, so don't use Right channels without Left ones
- Polyphony on signal inputs is replicated on outs

## Toggler / Toggler Compact
### Stereo signal toggle switch router, with VCA and ASR envelope generator, in regular and compact form factor
#### - DESCRIPTION
- Toggled VCA with builtin ASR envelope generator
- Toggled ASR envelope generator
- mute/unmute CVs or mono/stereo AUDIO signals according to an ASR envelope activated by a Gate or Toggle Triggers

![toggler](https://user-images.githubusercontent.com/80784296/211222030-1a5b4e86-eccd-4e4f-ae56-65efd100e336.JPG)

#### - INSTRUCTIONS
**TOGGLE MODE**

On receiving a trigger on TRIG input, it will send the L+(R) inputs to L+(R) outputs and set the GATE output to high. On next trigger it will interrupt L+(R) outputs and set the GATE output to low.

Attack, Sustain and Release knobs set the envelope of the routed signal.

A, S, R CVinputs are added to respective knob values, Toggler module has attenuverters.

If L or (R) inputs are not connected, L and (R) outputs will provide just the envelope, so a mono signal can be connected to L input to route it to L output and nothing connected to (R) input to have the envelope on (R) output.

A trigger on RESET input will reset the toggle state.

Polyphony on L/(R) inputs is replicated on outs.  

**GATE MODE**

The same of toggle mode, but the signals will be routed only while GATE input is in a high state.

NOTE: If a new GATE or Toggle TRIGGER is detected on Attack or Release phases, the envelope ramp will immediately restart from the reached point, as a regular envelope generator and not like a function generator.  

**SPECIAL BEHAVIORS**

If Attack is set to 1ms (and release is set greater than 1ms) and a new GATE or Toggle TRIGGER is detected before Release phase has ended, the next Release phase will start from the previous reached release point.

If Release is set to 1ms (and attack is set greater than 1ms) and a new GATE or Toggle TRIGGER is detected before Attack phase has ended, the next Attack phase will start from the previous reached Attack point.

These behaviors are more understandable connecting a scope on the output.

#### Context Menu
- Initialize On Start: discards previous module state on VCV restart

## Wavetabler
### wavetable sample player

#### - DESCRIPTION
- 1-cycle waveforms player
- ±24 semitones tuning and v/oct input with polyphony
- envelope generator, reverse, pingpong
- anti-aliasing filter

![wavetabler](https://user-images.githubusercontent.com/80784296/222272709-33ee0e06-bcfa-4f20-8428-6579940f1f0f.JPG)

#### - INSTRUCTIONS
Load sample using context menu or right-click in the waveform display area to access quick load menu.  
Once a sample is loaded samples in the same folder can be browser using Previous and Next buttons below the display.  

REV button changes the playback start direction.

PNG button enables PingPong mode: playback direction is inverted when sample reaches its edges.  

The envelope knobs can be external modulated with attenuverted CVinputs.

Tune knob with its attenuverted CVinput, can tune up or down the sample with a ±2 octave range (semitone scale).  

Master knob, with its attenuverted CVinput, sets the output volume from 0 to 200%. Limit switch is a hard clip limiter with a ±5v range. A led clip light warns of clipping.  

#### Context Menu
Please refer to sickoPlayer documentation.

## CREDITS
The Component Library graphics for these modules are copyright © VCV and licensed under [CC BY-NC 4.0](https://creativecommons.org/licenses/by-nc/4.0/)  

Thanks to [Squinkylabs](https://github.com/squinkylabs), [Firo Lightfog](https://github.com/firolightfog) and [AuxMux](https://instagram.com/aux.mux) for help and testings, and all the [Vcv community](https://community.vcvrack.com)  
Thanks to [Omri Cohen](https://omricohen-music.com/) for support  
Thanks to [Clément Foulc](https://github.com/cfoulc) for creating [cfPlayer](https://library.vcvrack.com/cf/PLAYER), which was the basis and inspiration for writing all the sampler modules in this collection  
