#pragma once

class Layout {
	public:
		Layout();

		void Init();

		int GetBoardX();
		void SetBoardX(int value);
		int GetBoardY();
		void SetBoardY(int value);

		int GetOutputX();
		void SetOutputX(int value);
		int GetOutputY();
		void SetOutputY(int value);

		int GetOutputWidth();
		void SetOutputWidth(int value);
		int GetOutputHeight();
		void SetOutputHeight(int value);

		int GetLegendX();
		void SetLegendX(int value);
		int GetLegendY();
		void SetLegendY(int value);

	private:
		int BOARD_X;
		int BOARD_Y;

		int OUTPUT_X;
		int OUTPUT_Y;
		int output_width;
		int output_height;

		int LEGEND_X;
		int LEGEND_Y;
};