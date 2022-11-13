#include "plugin.hpp"

struct Parking : Module {
	enum ParamId {
		PARAMS_LEN
	};
	enum InputId {
		ENUMS(IN_INPUT,16),
		INPUTS_LEN
	};
	enum OutputId {
		ENUMS(OUT_OUTPUT,16),
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	Parking() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configInput(IN_INPUT, "Parking #1");
		configInput(IN_INPUT+1, "Parking #2");
		configInput(IN_INPUT+2, "Parking #3");
		configInput(IN_INPUT+3, "Parking #4");
		configInput(IN_INPUT+4, "Parking #5");
		configInput(IN_INPUT+5, "Parking #6");
		configInput(IN_INPUT+6, "Parking #7");
		configInput(IN_INPUT+7, "Parking #8");
		configInput(IN_INPUT+8, "Parking #9");
		configInput(IN_INPUT+9, "Parking #10");
		configInput(IN_INPUT+10, "Parking #11");
		configInput(IN_INPUT+11, "Parking #12");
		configInput(IN_INPUT+12, "Parking #13");
		configInput(IN_INPUT+13, "Parking #14");
		configInput(IN_INPUT+14, "Parking #15");
		configInput(IN_INPUT+15, "Parking #16");

		configOutput(OUT_OUTPUT, "Parking #1");
		configOutput(OUT_OUTPUT+1, "Parking #2");
		configOutput(OUT_OUTPUT+2, "Parking #3");
		configOutput(OUT_OUTPUT+3, "Parking #4");
		configOutput(OUT_OUTPUT+4, "Parking #5");
		configOutput(OUT_OUTPUT+5, "Parking #6");
		configOutput(OUT_OUTPUT+6, "Parking #7");
		configOutput(OUT_OUTPUT+7, "Parking #8");
		configOutput(OUT_OUTPUT+8, "Parking #9");
		configOutput(OUT_OUTPUT+9, "Parking #10");
		configOutput(OUT_OUTPUT+10, "Parking #11");
		configOutput(OUT_OUTPUT+11, "Parking #12");
		configOutput(OUT_OUTPUT+12, "Parking #13");
		configOutput(OUT_OUTPUT+13, "Parking #14");
		configOutput(OUT_OUTPUT+14, "Parking #15");
		configOutput(OUT_OUTPUT+15, "Parking #16");
	}

	void process(const ProcessArgs& args) override {

	}
};

struct ParkingWidget : ModuleWidget {
	ParkingWidget(Parking* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/Parking.svg")));

		addChild(createWidget<ScrewBlack>(Vec(0, 0)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewBlack>(Vec(0, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewBlack>(Vec(box.size.x - RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));		

		float x1 = 8;
		float x2 = 19.5;
		float ys = 34;
		float y = 11.5;

		for (int i=0;i<8;i++) {
			addInput(createInputCentered<PJ301MPort>(mm2px(Vec(x1, ys+(y*i))), module, Parking::IN_INPUT+i));
			addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(x2, ys+(y*i))), module, Parking::OUT_OUTPUT+i));
		}

		x1 = 30.5;
		x2 = 42;
		for (int i=8;i<16;i++) {
			addInput(createInputCentered<PJ301MPort>(mm2px(Vec(x1, ys+(y*(i-8)))), module, Parking::IN_INPUT+i));
			addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(x2, ys+(y*(i-8)))), module, Parking::OUT_OUTPUT+i));
		}
	}

};

Model* modelParking = createModel<Parking, ParkingWidget>("Parking");