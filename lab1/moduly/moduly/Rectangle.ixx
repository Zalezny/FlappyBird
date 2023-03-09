export module Rectangle;


export class RectangleClass {

public:
	RectangleClass() {}
	~RectangleClass() {}
	
	double circuit(double x, double y) {
		return (2 * x) + (2 * y);
	}

	double field(double x, double y) {
		return x * y;
	}

};
