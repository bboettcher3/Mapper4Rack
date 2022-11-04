#include "plugin.hpp"


struct Mapper4Rack : Module {
	enum ParamId {
		PARAMS_LEN
	};
	enum InputId {
		SRC1_INPUT,
		SRC2_INPUT,
		SRC3_INPUT,
		SRC4_INPUT,
		SRC5_INPUT,
		SRC6_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		DST1_OUTPUT,
		DST2_OUTPUT,
		DST3_OUTPUT,
		DST4_OUTPUT,
		DST5_OUTPUT,
		DST6_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		LIGHTS_LEN
	};

	Mapper4Rack() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configInput(SRC1_INPUT, "");
		configInput(SRC2_INPUT, "");
		configInput(SRC3_INPUT, "");
		configInput(SRC4_INPUT, "");
		configInput(SRC5_INPUT, "");
		configInput(SRC6_INPUT, "");
		configOutput(DST1_OUTPUT, "");
		configOutput(DST2_OUTPUT, "");
		configOutput(DST3_OUTPUT, "");
		configOutput(DST4_OUTPUT, "");
		configOutput(DST5_OUTPUT, "");
		configOutput(DST6_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
		
	}
};


struct Mapper4RackWidget : ModuleWidget {
	Mapper4RackWidget(Mapper4Rack* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/Mapper4Rack.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.566, 42.0)), module, Mapper4Rack::SRC1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.566, 57.301)), module, Mapper4Rack::SRC2_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.566, 72.601)), module, Mapper4Rack::SRC3_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.566, 87.902)), module, Mapper4Rack::SRC4_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.566, 103.202)), module, Mapper4Rack::SRC5_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(7.566, 118.502)), module, Mapper4Rack::SRC6_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.849, 42.0)), module, Mapper4Rack::DST1_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.849, 57.301)), module, Mapper4Rack::DST2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.849, 72.601)), module, Mapper4Rack::DST3_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.849, 87.902)), module, Mapper4Rack::DST4_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.849, 103.202)), module, Mapper4Rack::DST5_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(22.849, 118.502)), module, Mapper4Rack::DST6_OUTPUT));
	}
};


Model* modelMapper4Rack = createModel<Mapper4Rack, Mapper4RackWidget>("Mapper4Rack");