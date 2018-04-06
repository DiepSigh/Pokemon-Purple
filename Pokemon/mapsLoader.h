#ifndef _MAPSLOADER_H
#define _MAPSLOADER_H

#include "gameEntity.h"

class MapsLoader : public GameEntity {
protected:

	Texture
		//MasterMap
		*masterMap,

		//Common
		*Curtains, *Floor, *Floor2, *Floor2Shadow, *Flower1, *Flower2, *Tv, *Window, *Wall, *Chair, *Bookshelf1_1, *Bookshelf1_2, *Bookshelf2_1, *Bookshelf2_2,
		*TableTopLeft, *TableTopRight, *Bottom_Table_Left, *Bottom_Table_Right, *Picture,

		//StartRoom
		*srComputer1, *srComputer2, *srBed1, *srBed2, *srConsole, *srDownstairs, *srTableWall1, *srTableWall2, *srTable1, *srTable2,

		//PlayersHouse
		*phExit, *phTable1, *phTable2, *phUpstairs,

		//reserchLab
		*rlBigTableBottomMiddle, *rlBigTableTopMiddle, *rlBigTableBottomLeft, *rlBigTableBottomRight, *rlTableBook1, *rlTableBook2, *rlComputerTable1, *rlComputerTable2, *rlExit, *rlFloor, *rlFlyer, *rlWall,

		//PokemonMart
		*pmCashbox, *pmCashboxBottom, *pmCashboxBottomLeft, *pmCooler1, *pmCooler2, *pmExit, *pmShelfCashierBottom1,
		*pmShelfCashierBottom2, *pmShelfCashier1, *pmShelfCashier2, *pmShelf1, *pmShelf2, *pmShelf3, *pmShelf4, *pmSignSale, *pmSignSaleBottom,

		//PokemonCenter
		*pcColumn1, *pcColumn2, *pcColumnEnd, *pcComputer1, *pcComputer2, *pcExit, *pcFloor, *pcFloorShadow, *pcFlower1, *pcFlower2, *pcLongDesk1, *pcLongDesk2,
		*pcLongDesk3, *pcLongDesk4, *pcPicture1, *pcPicture2, *pcPokemonHeal1, *pcPokemonHeal2, *pcPokemonHeal3, *pcPokemonHeal4, *pcSofa1, *pcSofa2,
		*pcSofaFloor1, *pcWayBackRoom, *pcWall,

		//PokemonSchool
		*psBoard1, *psBoard2, *psFloor, *psTable1, *psTable2, *psExit, *psWall,

		//ViridianCityHouse
		*vchClipboard,
		
		//PokemonLeague
		*plCarpet1, *plCarpet2, *plDoor, *plFloor, *plStatue1, *plStatue2, *plStatue3;


public:
	MapsLoader();
	~MapsLoader();


};


#endif //!MAPSLODER_H
