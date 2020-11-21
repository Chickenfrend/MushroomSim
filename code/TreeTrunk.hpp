namespace Objects{
	class TreeTrunk{
		private:
			String treeType;
			bool isDeciduous; 
			int maxDistance;
			int ageYears;
			float height;
			float circumference;
			float maxHeight;

		public:
			void age();
			void growRoots();
			void growTaller();
	}
}
