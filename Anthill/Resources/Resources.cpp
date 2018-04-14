#include "Resources.h"



Resources::Resources()
{
}


Resources::~Resources()
{
}

void Resources::LoadTextures(string dirt_, string wood_, string ant_, string queen_, string cath_, 
	string beetle_, string leaf_, string stick_, string anthill_, string fence_)
{
	/*dirtTex.loadFromFile(dirt_);
	woodTex.loadFromFile(wood_);
	
	catherpillarTex.loadFromFile(cath_);
	beetleTex.loadFromFile(beetle_);
	leafTex.loadFromFile(leaf_);
	stickTex.loadFromFile(stick_);
	anthillTex.loadFromFile(anthill_);*/
	queenTex.loadFromFile(queen_);
	antTex.loadFromFile(ant_);
	stickTex.loadFromFile(stick_);
	leafTex.loadFromFile(leaf_);
	//fenceTex.loadFromFile(fence_);

}

void Resources::LoadShaders(string vertexStd_, string fragmentStd_, 
	string vertexSelected_, string fragmentSelected_)
{
	standartShader = Shader(vertexStd_.c_str(), fragmentStd_.c_str());
	selectedShader = Shader(vertexSelected_.c_str(), fragmentSelected_.c_str());
}

void Resources::LoadModels(char * ant, char * queen, char * catherpillar, char * beetle,
	char * anthill, char * leaf, char * stick, char * fence)
{
	antModel = ant;
	queenModel = queen;
	catherpillarModel = catherpillar;
	beetleModel = beetle;
	anthillModel = anthill;
	leafModel = leaf;
	stickModel = stick;
	//fenceModel = fence;
}

void Resources::LoadFonts(string uiAnthillNumbers)
{
	if (!anthillFontNumbers.loadFromFile(uiAnthillNumbers))
	{
		std::cout << "Failed font loading";
	}
}

