	class UndergroundSystem {
	public:
		unordered_map<string, pair<double, int>> mp;

		unordered_map<int, pair<string, int>>rest;
		UndergroundSystem() {

		}

		void checkIn(int id, string stationName, int t) {
			rest[id] = {stationName, t};
		}

		void checkOut(int id, string stationName, int t) {
			string str = rest[id].first + "->" + stationName;
			double time = t - checkin[id].second;
			mp[str].first += time;
			mp[str].second++;
		}

		double getAverageTime(string startStation, string endStation) {
			string s = startStation + "->" + endStation;
			return mp[s].first / mp[s].second;
		}
	};
