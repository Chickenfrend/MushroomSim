#include "GroundInfoWriter.hpp"
#include <SFML/System/String.hpp>

GroundInfoWriter::GroundInfoWriter(Ground& ground):shroom(ground.getMushroom()){
	hasTreeRoot = ground.hasTreeRoot();
	hasTreeTrunk = ground.hasTreeTrunk();
	hasMushroom = ground.hasMushroom();

	moisture = ground.getMoisture();
	density = ground.getDensity();
	nutrients = ground.getNutrients();

	if(hasTreeTrunk){
		trunkName = ground.getTreeTrunk()->getTreeType();
	}
	if(hasTreeRoot){
		rootName = ground.getTreeRoot()->getTreeType();
	}
	if(hasMushroom){
		shroomName = ground.getMushroom()->getShroomType();
	}
}

void GroundInfoWriter::writeToBox(tgui::TextBox::Ptr infoBox){
	infoBox->addText(sf::String("Ground Density: " + std::to_string(density) + "\n"));
	infoBox->addText(sf::String("Ground Moisture: " + std::to_string(moisture) + "\n"));
	infoBox->addText(sf::String("Ground Nutrients: " + std::to_string(nutrients) + "\n"));

	if(hasTreeTrunk){
		infoBox->addText(sf::String("Tree: ") + trunkName + "\n\n");
	}
	if(hasMushroom){
		infoBox->addText(sf::String("Mushroom: ") + shroomName + "\n");
		infoBox->addText(sf::String("	Age: \n"));
		infoBox->addText(sf::String("		Months: " + std::to_string(shroom->getAgeMonths()) + "\n"));
		infoBox->addText(sf::String("		Days: " + std::to_string(shroom->getAgeDays())) + "\n");
		infoBox->addText(sf::String("		Hours: " + std::to_string(shroom->getAgeHours())) + "\n");
		infoBox->addText(sf::String("	Density: " + std::to_string(shroom->getDensity()) + "\n"));
		infoBox->addText(sf::String("	Moisture: " + std::to_string(shroom->getMoisturePercent()) + "\n"));
		infoBox->addText(sf::String("	Nutrients: " + std::to_string(shroom->getStoredNutrients()) + "\n"));

	}
	if(hasTreeRoot){
		infoBox->addText(sf::String("Root: ") + rootName + "\n");
	}

}
