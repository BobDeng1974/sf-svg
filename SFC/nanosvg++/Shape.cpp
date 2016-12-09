#include "Shape.hpp"

namespace nsvg {
	Shape::Shape(const cstyle::ShapeStruct *ptr)
		: internal { ptr }
	{ }

	std::string Shape::getId() const {
		return std::string(this->internal->id);
	}

	cstyle::Paint Shape::getFill() const {
		return this->internal->fill;
	}

	cstyle::Paint Shape::getStroke() const {
		return this->internal->stroke;
	}

	float Shape::getOpacity() const {
		return this->internal->opacity;
	}

	float Shape::getStrokeWidth() const {
		return this->internal->strokeWidth;
	}

	float Shape::getStrokeDashOffset() const {
		return this->internal->strokeDashOffset;
	}

	const float* Shape::getStrokeDashArray() const {
		return this->internal->strokeDashArray;
	}

	size_t Shape::getStrokeDashCount() const {
		return this->internal->strokeDashCount;
	}

	cstyle::LineJoin Shape::getStrokeLineJoin() const {
		return this->internal->strokeLineJoin;
	}

	cstyle::LineCap Shape::getStrokeLineCap() const {
		return this->internal->strokeLineCap;
	}

	cstyle::Flags Shape::getFlags() const {
		return this->internal->flags;
	}

	const float* Shape::getBounds() const {
		return this->internal->bounds;
	}

	const cstyle::Path* Shape::getPaths() const {
		return this->internal->paths;
	}

	Shape Shape::getNextShape() const {
		return Shape(this->internal->next);
	}
}