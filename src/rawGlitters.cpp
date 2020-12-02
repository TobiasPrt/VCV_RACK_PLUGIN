#include "plugin.hpp"


struct RawGlitters : Module {
	enum ParamIds {
		ENABLED_PARAM,
		RES_PARAM,
		DEREZ_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		INPUT_1_INPUT,
		INPUT_2_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		OUTPUT_2_OUTPUT,
		OUTPUT_1_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		NUM_LIGHTS
	};

	RawGlitters() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
		configParam(ENABLED_PARAM, 0.f, 1.f, 0.f, "");
		configParam(RES_PARAM, 0.f, 1.f, 0.f, "");
		configParam(DEREZ_PARAM, 0.f, 1.f, 0.f, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct RawGlittersWidget : ModuleWidget {
	RawGlittersWidget(RawGlitters* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/rawGlitters.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<CKSS>(mm2px(Vec(9.958, 40.362)), module, RawGlitters::ENABLED_PARAM));
		addParam(createParamCentered<CKSS>(mm2px(Vec(20.542, 40.411)), module, RawGlitters::RES_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(15.25, 72.482)), module, RawGlitters::DEREZ_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(8.819, 96.346)), module, RawGlitters::INPUT_1_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(21.64, 96.346)), module, RawGlitters::INPUT_2_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(21.682, 113.214)), module, RawGlitters::OUTPUT_2_OUTPUT));
		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(8.846, 113.333)), module, RawGlitters::OUTPUT_1_OUTPUT));
	}
};


Model* modelRawGlitters = createModel<RawGlitters, RawGlittersWidget>("rawGlitters");