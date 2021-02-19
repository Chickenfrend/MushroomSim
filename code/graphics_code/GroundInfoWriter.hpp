#ifndef GROUND_INFO_WRITER
#define GROUND_INFO_WRITER

#include "../Ground.hpp"
#include <TGUI/TGUI.hpp>
#include <string>
using std::string;

class GroundInfoWriter {
	public:
	GroundInfoWriter(Ground &ground);
	void writeToBox(tgui::TextBox::Ptr infoBox);

	private:
	Mushroom *shroom;
	float moisture;
	float density;
	int nutrients;
	bool hasMushroom = false;
	bool hasTreeRoot = false;
	bool hasTreeTrunk = false;
	string shroomName = "";
	string rootName = "";
	string trunkName = "";
};

#endif
