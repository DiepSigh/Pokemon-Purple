#include "mapsLoader.h"


MapsLoader::MapsLoader() {
	
	//masterMap
	masterMap = new Texture("maps/MasterMap.png", 0, 0, 2592, 5504);

	//common
	Curtains = new Texture("maps/curtains.png", 0, 0, 32, 32);
	Floor = new Texture("maps/floor.png", 0, 0, 32, 32);
	Flower1 = new Texture("maps/flower1.png", 0, 0, 32, 32);
	Flower2 = new Texture("maps/flower2.png", 0, 0, 32, 32);
	Tv = new Texture("maps/tv.png", 0, 0, 32, 32);
	Wall = new Texture("maps/wall.png", 0, 0, 32, 32);
	Window = new Texture("maps/window.png", 0, 0, 32, 32);
	Bookshelf1_1 = new Texture("maps/bookshelf1_1.png", 0, 0, 32, 32);
	Bookshelf1_2 = new Texture("maps/bookshelf1_2.png", 0, 0, 32, 32);
	Bookshelf2_1 = new Texture("maps/bookshelf2_1.png", 0, 0, 32, 32);
	Bookshelf2_2 = new Texture("maps/bookshelf2_2.png", 0, 0, 32, 32);
	Chair = new Texture("maps/chair.png", 0, 0, 32, 32);
	Floor = new Texture("maps/floor.png", 0, 0, 32, 32);
	Floor2 = new Texture("maps/floor2.png", 0, 0, 32, 32);
	Floor2Shadow = new Texture("maps/floor2shadow.png", 0, 0, 32, 32);
	TableTopLeft = new Texture("maps/table_top_left.png", 0, 0, 32, 32);
	TableTopRight = new Texture("maps/table_top_right.png", 0, 0, 32, 32);
	Bottom_Table_Left = new Texture("maps/table_bottom_left.png", 0, 0, 32, 32);
	Bottom_Table_Right = new Texture("maps/table_bottom_right.png", 0, 0, 32, 32);
	Picture = new Texture("maps/picture.png", 0, 0, 32, 32);

	//startRoom
	srComputer1 = new Texture("maps/sr_computer1.png", 0, 0, 32, 32);
	srComputer2 = new Texture("maps/sr_computer2.png", 0, 0, 32, 32);
	srBed1 = new Texture("maps/sr_bed1.png", 0, 0, 32, 32);
	srBed2 = new Texture("maps/sr_bed2.png", 0, 0, 32, 32);
	srConsole = new Texture("maps/sr_console.png", 0, 0, 32, 32);
	srDownstairs = new Texture("maps/sr_downstairs.png", 0, 0, 32, 32);
	srTableWall1 = new Texture("maps/sr_table_wall1.png", 0, 0, 32, 32);
	srTableWall2 = new Texture("maps/sr_table_wall2.png", 0, 0, 32, 32);

	//playerHouse 
	phExit = new Texture("maps/ph_exit.png", 0, 0, 32, 32);
	phTable1 = new Texture("maps/ph_table1.png", 0, 0, 32, 32);
	phTable2 = new Texture("maps/ph_table2.png", 0, 0, 32, 32);
	phUpstairs = new Texture("maps/ph_upstairs.png", 0, 0, 32, 32);
	
	//researchLab
	rlBigTableBottomMiddle = new Texture("maps/rl_big_table_bottom_middle.png", 0, 0, 32, 32);
	rlBigTableTopMiddle = new Texture("maps/rl_big_table_top_middle.png", 0, 0, 32, 32);
	rlBigTableBottomLeft = new Texture("maps/rl_table_bottom_left.png", 0, 0, 32, 32);
	rlBigTableBottomRight = new Texture("maps/rl_table_bottom_right.png", 0, 0, 32, 32);
	rlComputerTable1 = new Texture("maps/rl_computer_table1.png", 0, 0, 32, 32);
	rlComputerTable2 = new Texture("maps/rl_computer_table2.png", 0, 0, 32, 32);
	rlTableBook1 = new Texture("maps/rl_table_book1.png", 0, 0, 32, 32);
	rlTableBook2 = new Texture("maps/rl_table_book2.png", 0, 0, 32, 32);
	rlExit = new Texture("maps/rl_exit.png", 0, 0, 32, 32);
	rlFloor = new Texture("maps/rl_floor.png", 0, 0, 32, 32);
	rlFlyer = new Texture("maps/rl_flyer.png", 0, 0, 32, 32);
	rlWall = new Texture("maps/rl_wall.png", 0, 0, 32, 32);

	//pokemonMart
	pmCashbox = new Texture("maps/pm_cashbox.png", 0, 0, 32, 32);
	pmCashboxBottom = new Texture("maps/pm_cashbox_bottom.png", 0, 0, 32, 32);
	pmCashboxBottomLeft = new Texture("maps/pm_cashbox_bottom_left.png", 0, 0, 32, 32);
	pmCooler1 = new Texture("maps/pm_cooler1.png", 0, 0, 32, 32);
	pmCooler2 = new Texture("maps/pm_cooler2.png", 0, 0, 32, 32);
	pmExit = new Texture("maps/pm_exit.png", 0, 0, 32, 32);
	pmShelfCashierBottom1 = new Texture("maps/pm_shelf_cashier_bottom1.png", 0, 0, 32, 32);
	pmShelfCashierBottom2 = new Texture("maps/pm_shelf_cashier_bottom2.png", 0, 0, 32, 32);
	pmShelfCashier1 = new Texture("maps/pm_shelf_cashier1.png", 0, 0, 32, 32);
	pmShelfCashier2 = new Texture("maps/pm_shelf_cashier2.png", 0, 0, 32, 32);
	pmShelf1 = new Texture("maps/pm_shelf1.png", 0, 0, 32, 32);
	pmShelf2 = new Texture("maps/pm_shelf2.png", 0, 0, 32, 32);
	pmShelf3 = new Texture("maps/pm_shelf3.png", 0, 0, 32, 32);
	pmShelf4 = new Texture("maps/pm_shelf4.png", 0, 0, 32, 32);
	pmSignSale = new Texture("maps/pm_sign_sale.png", 0, 0, 32, 32);
	pmSignSaleBottom = new Texture("maps/pm_sign_sale_bottom.png", 0, 0, 32, 32);

	//pokemonCenter
	pcColumn1 = new Texture("maps/pc_column1.png", 0, 0, 32, 32);
	pcColumn2 = new Texture("maps/pc_column2.png", 0, 0, 32, 32);
	pcColumnEnd = new Texture("maps/pc_column_end.png", 0, 0, 32, 32);
	pcComputer1 = new Texture("maps/pc_computer1.png", 0, 0, 32, 32);
	pcComputer2 = new Texture("maps/pc_computer2.png", 0, 0, 32, 32);
	pcExit = new Texture("maps/pc_exit.png", 0, 0, 32, 32);
	pcLongDesk1 = new Texture("maps/pc_long_desk1.png", 0, 0, 32, 32);
	pcLongDesk2 = new Texture("maps/pc_long_desk2.png", 0, 0, 32, 32);
	pcLongDesk3 = new Texture("maps/pc_long_desk3.png", 0, 0, 32, 32);
	pcLongDesk4 = new Texture("maps/pc_long_desk4.png", 0, 0, 32, 32);
	pcPicture1 = new Texture("maps/pc_picture1.png", 0, 0, 32, 32);
	pcPicture2 = new Texture("maps/pc_picture2.png", 0, 0, 32, 32);
	pcPokemonHeal1 = new Texture("maps/pc_pokemon_heal1.png", 0, 0, 32, 32);
	pcPokemonHeal2 = new Texture("maps/pc_pokemon_heal2.png", 0, 0, 32, 32);
	pcPokemonHeal3 = new Texture("maps/pc_pokemon_heal3.png", 0, 0, 32, 32);
	pcPokemonHeal4 = new Texture("maps/pc_pokemon_heal4.png", 0, 0, 32, 32);
	pcSofa1 = new Texture("maps/pc_sofa1.png", 0, 0, 32, 32);
	pcSofa2 = new Texture("maps/pc_sofa2.png", 0, 0, 32, 32);
	pcSofaFloor1 = new Texture("maps/pc_sofa_floor1.png", 0, 0, 32, 32);
	pcWall = new Texture("maps/pc_wall.png", 0, 0, 32, 32);
	pcWayBackRoom = new Texture("maps/pc_way_back_room.png", 0, 0, 32, 32);

	//pokemonSchool
	psBoard1 = new Texture("maps/ps_board1.png", 0, 0, 32, 32);
	psBoard2 = new Texture("maps/ps_board2.png", 0, 0, 32, 32);
	psExit = new Texture("maps/ps_exit.png", 0, 0, 32, 32);
	psTable1 = new Texture("maps/ps_table1.png", 0, 0, 32, 32);
	psTable2 = new Texture("maps/ps_table2.png", 0, 0, 32, 32);

	//viridianCityHouse
	vchClipboard = new Texture("maps/vch_clipboard.png", 0, 0, 32, 32);
	
	//pokemonLeague
	plCarpet1 = new Texture("maps/pl_carpet1.png", 0, 0, 32, 32);
	plCarpet2 = new Texture("maps/pl_carpet2.png", 0, 0, 32, 32);
	plDoor = new Texture("maps/pl_door.png", 0, 0, 32, 32);
	plFloor = new Texture("maps/pl_floor.png", 0, 0, 32, 32);
	plStatue1 = new Texture("maps/pl_statue1.png", 0, 0, 32, 32);
	plStatue2 = new Texture("maps/pl_statue2.png", 0, 0, 32, 32);
	plStatue3 = new Texture("maps/pl_statue3.png", 0, 0, 32, 32);

}

MapsLoader::~MapsLoader() {}
