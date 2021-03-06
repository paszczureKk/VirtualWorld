#include "Layout.h"

Layout::Layout() {
	Init();
}

void Layout::Init() {
	SetBoardX(5);
	SetBoardY(5);

	SetOutputX(5);
	SetOutputY(30);
	SetOutputWidth(0);
	SetOutputHeight(0);

	SetLegendX(30);
	SetLegendY(5);

	SetLegendWidth(0);
	SetLegendHeigth(0);

	SetLegendWidth(35);
	SetLegendHeigth(20);
}

int Layout::GetBoardX() {
	return BOARD_X;
}
void Layout::SetBoardX(int value) {
	BOARD_X = value;
}

int Layout::GetBoardY() {
	return BOARD_Y;
}
void Layout::SetBoardY(int value) {
	BOARD_Y = value;
}

int Layout::GetOutputX() {
	return OUTPUT_X;
}
void Layout::SetOutputX(int value) {
	OUTPUT_X = value;
}

int Layout::GetOutputY() {
	return OUTPUT_Y;
}
void Layout::SetOutputY(int value) {
	OUTPUT_Y = value;
}

int Layout::GetOutputWidth() {
	return output_width;
}
void Layout::SetOutputWidth(int value) {
	if (value > 0) {
		if (output_width < value) {
			output_width = value;
		}
	}
	else {
		output_width = 0;
	}
}

int Layout::GetOutputHeight() {
	return output_height;
}
void Layout::SetOutputHeight(int value) {
	if (value > 0) {
		output_height += value;
	}
	else {
		output_height = 0;
	}
}

int Layout::GetLegendX() {
	return LEGEND_X;
}
void Layout::SetLegendX(int value) {
	LEGEND_X = value;
}

int Layout::GetLegendY() {
	return LEGEND_Y;
}
void Layout::SetLegendY(int value) {
	LEGEND_Y = value;
}

int Layout::GetLegendWidth() {
	return legend_width;
}
void Layout::SetLegendWidth(int value) {
	if (value > 0) {
		if (legend_width < value) {
			legend_width = value;
		}
	}
	else {
		legend_width = 0;
	}
}
int Layout::GetLegendHeight() {
	return legend_height;
}
void Layout::SetLegendHeigth(int value) {
	if (value > 0) {
		legend_height += value;
	}
	else {
		legend_height = 0;
	}
}