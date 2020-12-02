class Ground{
	private:
		int density;
		int moisture;
		TreeRoot root;
		TreeTrunk trunk;
		Mushroom mushroom;

	public:
		getDensity();
		setDensity();
		getMoisture();
		setMoisture();
		getTreeRoot();
		getTreeTrunk();
		getMushroom();
		update();
}
