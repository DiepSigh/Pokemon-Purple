#ifndef _MAPSLOADER_H
#define _MAPSLOADER_H

#include "gameEntity.h"

class MapsLoader : public GameEntity {
protected:

	Texture

		//Common
		* Curtains, *Floor, *Flower1, *Flower2, *Tv, *Window, *Wall, *Chair, *Bookshelf1_1, *Bookshelf1_2, *Bookshelf2_1, *Bookshelf2_2, *Bottom_Table_Left, *Bottom_Table_Right,

		//StartRoom
		*srComputer1, *srComputer2, *srBed1, *srBed2, *srConsole, *srDownstairs, *srTableWall1, *srTableWall2, *srTable1, *srTable2,

		//Player House
		*phExit, *phTable1, *phTable2, *phUpstairs,

		//redHouse
		*rhExit, *rhPicture, *rhTable1, *rhTable2,

		//reserchLab
		*rlBigTableBottomMiddle, *rlBigTableTopLeft, *rlBigTableTopMiddle, *rlBigTableTopRight, *rlTableBook1, *rlTableBook2, *rlTableBottomLeft, *rlTableBottomRight,
		*rlBookshelf1, *rlBookshelf2, *rlComputerTable1, *rlComputerTable2, *rlExit, *rlFloor, *rlFlyer, *rlWall,

		//pokemonMart
		*pmCashbox, *pmCashboxBottom, *pmCashboxBottomLeft, *pmCooler1, *pmCooler2, *pmExit, *pmFloor, *pmFloorShadow, *pmShelfCashierBottom1,
		*pmShelfCashierBottom2, *pmShelfCashier1, *pmShelfCashier2, *pmShelf1, *pmShelf2, *pmShelf3, *pmShelf4, *pmSignSale, *pmSignSaleBottom,

		//pokemonCenter
		*pcColumn1, *pcColumn2, *pcColumnEnd, *pcComputer1, *pcComputer2, *pcExit, *pcFloor, *pcFloorShadow, *pcFlower1, *pcFlower2, *pcLongDesk1, *pcLongDesk2,
		*pcLongDesk3, *pcLongDesk4, *pcPicture1, *pcPicture2, *pcPokemonHeal1, *pcPokemonHeal2, *pcPokemonHeal3, *pcPokemonHeal4, *pcSofa1, *pcSofa2,
		*pcSofaFloor1, *pcSofaFloor2, *pcWayBackRoom, *pcWall,

		//pokemonSchool
		*psBoard1, *psBoard2, *psExit, *psFloor, *psTable1, *psTable2, *psTable3, *psTable4, *psWall;


public:
	MapsLoader();
	~MapsLoader();

};


#endif //!MAPSLODER_H
