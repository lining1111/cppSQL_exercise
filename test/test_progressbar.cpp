//
// Created by lining on 2/14/25.
//
#include "progressbar/progressbar.h"

int main() {
    if (0) {
        //3rd
        indicators::ProgressBar bar;
        bar.set_option(indicators::option::PrefixText{"Loading"});
        bar.set_option(indicators::option::ShowPercentage{true});
        bar.set_option(indicators::option::BarWidth{50});
        bar.set_option(indicators::option::Fill{"█"});
        bar.set_option(indicators::option::Lead{"█"});
        bar.set_option(indicators::option::Remainder{"-"});

        for (size_t i = 0; i <= 100; ++i) {
            bar.set_progress(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }

        bar.mark_as_completed();
    }{
        //std
        int total = 100; // 总任务量
        for (int completed = 0; completed <= total; ++completed) {
            printProgressBar(completed, total, '#');
            std::cout << std::endl; // 打印完成后换行
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
        }
    }
    return 0;
}