export module Rectangle;


export class Rectangle {

public:
	Rectangle() {}
	~Rectangle() {}
	
	double circuit(double x, double y) {
		return (2 * x) + (2 * y);
	}

	double field(double x, double y) {
		return x * y;
	}

};
