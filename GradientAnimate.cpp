#include "emp/web/Animate.hpp"
#include "emp/web/web.hpp"

emp::web::Document doc{"target"};
double StepCounter = 0;
std::vector<std::vector<float>> cells;

class GradientAnimator : public emp::web::Animate {
    emp::web::Canvas canvas{500, 500, "canvas"};

    public:
        GradientAnimator() {
            doc << canvas;
            doc << GetToggleButton("Toggle");
            doc << GetStepButton("Step");
            int num_w_boxes = 10;
            int num_h_boxes = 10;

            cells.resize(num_w_boxes, std::vector<float>(num_h_boxes, 0));
        };

        void DoFrame() {
            canvas.Clear();
            canvas.Text(*new emp::Point(10, 10), std::to_string(StepCounter), "green");

            // canvas.Rect(20, 20, 100, 100, emp::ColorHSV(0, 0, StepCounter), "black");
            GenerateCells();
            StepCounter += 0.01;
        }

        void GenerateCells() {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    int x = i * 30;
                    int y = j * 30;
                    canvas.Rect(x, y, 30, 30, emp::ColorHSV(i/10, j/10, StepCounter), "black");
                    canvas.CenterText(x + 15, y + 15, std::to_string(i)+","+std::to_string(j), "yellow", "yellow");
                }
            }
        }
};

GradientAnimator animator;

int main() {
    animator.Step();
};

