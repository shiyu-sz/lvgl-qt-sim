
#include "../lvgl/lvgl.h"

#ifdef USE_SIM_LOG  // for dimulator this is defined in .pro file
#include "log.h"
#undef LV_LOG_USER
#define LV_LOG_USER LOG
#undef LV_LOG_ERROR
#define LV_LOG_ERROR LOG_E
#undef LV_LOG_WARN
#define LV_LOG_WARN LOG_W
#endif

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

void lvgl_page_1()
{
    /* 设置状态容器的样式 */
    static lv_style_t status_cont_style;
    lv_style_init(&status_cont_style);
    lv_style_set_bg_opa(&status_cont_style, 0);
    lv_style_set_radius(&status_cont_style, 0);
    lv_style_set_border_width(&status_cont_style, 0);
    lv_style_set_flex_flow(&status_cont_style, LV_FLEX_FLOW_COLUMN);

    /* 上方状态栏字体的样式 */
    static lv_style_t status_font_style;
    lv_style_init(&status_font_style);
    lv_style_set_text_font(&status_font_style, &lv_font_montserrat_16);
    lv_style_set_text_color(&status_font_style, lv_color_hex(0xFFFFFF));

    // 顶层容器
    lv_obj_t *root = lv_obj_create(lv_scr_act());       // 创建容器
    lv_obj_set_size(root, LV_HOR_RES, LV_VER_RES);      // 设置大小
    lv_obj_set_layout(root, LV_LAYOUT_FLEX);            // 设置布局
    lv_obj_set_flex_flow(root, LV_FLEX_FLOW_COLUMN);    // 垂直布局
    lv_obj_set_style_pad_gap(root, 0, 0);
    lv_obj_set_style_radius(root, 0, 0);                // 设置圆角
    lv_obj_set_style_pad_all(root, 0, 0);               // 设置边距
    lv_obj_set_style_border_width(root, 0, 0);          // 设置边框
    lv_obj_set_style_bg_color(root, lv_color_hex(0x000000), 0);

    // 上方的状态栏
    lv_obj_t *root1 = lv_obj_create(root);
    lv_obj_set_width(root1, LV_HOR_RES);            // 设置宽度
    lv_obj_set_layout(root1, LV_LAYOUT_FLEX);       // 设置布局
    lv_obj_set_flex_flow(root1, LV_FLEX_FLOW_ROW);  // 水平
    lv_obj_set_flex_align(root1, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);  // 设置对齐
    lv_obj_set_style_radius(root1, 0, 0);           // 设置圆角
    lv_obj_set_style_pad_all(root1, 0, 0);          // 设置边距
    lv_obj_set_style_border_width(root1, 0, 0);          // 设置边框
    lv_obj_set_flex_grow(root1, 1);                // 比例
    lv_obj_set_style_bg_color(root1, lv_color_hex(0x5f596e), 0);

    // 下方的运动参数
    lv_obj_t *root2 = lv_obj_create(root);
    lv_obj_set_width(root2, LV_HOR_RES);
    lv_obj_set_layout(root2, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(root2, LV_FLEX_FLOW_ROW);      // 水平
    lv_obj_set_flex_align(root2, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_radius(root2, 0, 0);           // 设置圆角
    lv_obj_set_style_pad_all(root2, 0, 0);
    lv_obj_set_style_border_width(root2, 0, 0);          // 设置边框
    lv_obj_set_flex_grow(root2, 3);
    lv_obj_set_style_bg_color(root2, lv_color_hex(0x000000), 0);

    // 时间图标
    lv_obj_t *status1 = lv_obj_create(root1);
    lv_obj_add_style(status1, &status_cont_style, 0);
    lv_obj_set_flex_align(status1, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    LV_IMG_DECLARE(settings_16dp_FFFFFF);
    lv_obj_t * img1 = lv_img_create(status1);
    lv_img_set_src(img1, &settings_16dp_FFFFFF);
    lv_obj_t *label1 = lv_label_create(status1);
    lv_label_set_text(label1, "00:00");
    lv_obj_add_style(label1, &status_font_style, 0);

    // 距离图标
    lv_obj_t *status2 = lv_obj_create(root1);
    lv_obj_add_style(status2, &status_cont_style, 0);
    lv_obj_set_flex_align(status2, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    LV_IMG_DECLARE(settings_16dp_FFFFFF);
    lv_obj_t * img2 = lv_img_create(status2);
    lv_img_set_src(img2, &settings_16dp_FFFFFF);
    lv_obj_t *label2 = lv_label_create(status2);
    lv_label_set_text(label2, "00.0");
    lv_obj_add_style(label2, &status_font_style, 0);

    // 卡路里图标
    lv_obj_t *status3 = lv_obj_create(root1);
    lv_obj_add_style(status3, &status_cont_style, 0);
    lv_obj_set_flex_align(status3, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    LV_IMG_DECLARE(settings_16dp_FFFFFF);
    lv_obj_t * img3 = lv_img_create(status3);
    lv_img_set_src(img3, &settings_16dp_FFFFFF);
    lv_obj_t *label3 = lv_label_create(status3);
    lv_label_set_text(label3, "0000");
    lv_obj_add_style(label3, &status_font_style, 0);

    // 速度图标
    lv_obj_t *status4 = lv_obj_create(root1);
    lv_obj_add_style(status4, &status_cont_style, 0);
    lv_obj_set_flex_align(status4, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    LV_IMG_DECLARE(settings_16dp_FFFFFF);
    lv_obj_t * img4 = lv_img_create(status4);
    lv_img_set_src(img4, &settings_16dp_FFFFFF);
    lv_obj_t *label4 = lv_label_create(status4);
    lv_label_set_text(label4, "00.0");
    lv_obj_add_style(label4, &status_font_style, 0);

    // 心率图标
    lv_obj_t *status5 = lv_obj_create(root1);
    lv_obj_add_style(status5, &status_cont_style, 0);
    lv_obj_set_flex_align(status5, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    LV_IMG_DECLARE(settings_16dp_FFFFFF);
    lv_obj_t * img5 = lv_img_create(status5);
    lv_img_set_src(img5, &settings_16dp_FFFFFF);
    lv_obj_t *label5 = lv_label_create(status5);
    lv_label_set_text(label5, "0000");
    lv_obj_add_style(label5, &status_font_style, 0);

    // 坡度图标
    lv_obj_t *status6 = lv_obj_create(root1);
    lv_obj_add_style(status6, &status_cont_style, 0);
    lv_obj_set_flex_align(status6, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    LV_IMG_DECLARE(settings_16dp_FFFFFF);
    lv_obj_t * img6 = lv_img_create(status6);
    lv_img_set_src(img6, &settings_16dp_FFFFFF);
    lv_obj_t *label6 = lv_label_create(status6);
    lv_label_set_text(label6, "00");
    lv_obj_add_style(label6, &status_font_style, 0);

    lv_obj_update_layout(root);

    // 无线投屏操作步骤
    lv_obj_t *status7 = lv_obj_create(root2);
    lv_obj_set_height(status7, lv_obj_get_height(root2));
    lv_obj_add_style(status7, &status_cont_style, 0);
    lv_obj_set_flex_align(status7, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_t *label7 = lv_label_create(status7);
    lv_label_set_text(label7, "ios111111111111");
    lv_obj_set_style_text_font(label7, &lv_font_montserrat_16, 0);
    lv_obj_set_style_text_color(label7, lv_color_hex(0xFFFFFF), 0);
    LV_IMG_DECLARE(ios_set_300);
    lv_obj_t * img7 = lv_img_create(status7);
    lv_img_set_src(img7, &ios_set_300);
    lv_img_set_zoom(img7, 100);
    lv_obj_set_style_pad_all(img7, 0, 0);               // 设置边距
    lv_obj_set_style_border_width(img7, 0, 0);          // 设置边框
    lv_obj_t * img71 = lv_img_create(status7);
    lv_img_set_src(img71, &ios_set_300);
    lv_img_set_zoom(img71, 100);
    lv_obj_set_style_pad_all(img71, 0, 0);               // 设置边距
    lv_obj_set_style_border_width(img71, 0, 0);          // 设置边框

    // 有线抽屏操作步骤
    lv_obj_t *status8 = lv_obj_create(root2);
    // lv_obj_set_height(status8, lv_obj_get_height(root2));
    lv_obj_add_style(status8, &status_cont_style, 0);
    lv_obj_set_flex_align(status8, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_t *label8 = lv_label_create(status8);
    lv_label_set_text(label8, "ios");
    lv_obj_set_style_text_font(label8, &lv_font_montserrat_16, 0);
    lv_obj_set_style_text_color(label8, lv_color_hex(0xFFFFFF), 0);
    LV_IMG_DECLARE(ios_set_300);
    lv_obj_t * img8 = lv_img_create(status8);
    lv_img_set_src(img8, &ios_set_300);
    lv_img_set_zoom(img8, 150);
    lv_obj_t * img81 = lv_img_create(status8);
    lv_img_set_src(img81, &ios_set_300);
    lv_img_set_zoom(img81, 150);

    // 注意事项
    lv_obj_t *status9 = lv_obj_create(root2);
    // lv_obj_set_height(status9, lv_obj_get_height(root2));
    lv_obj_add_style(status9, &status_cont_style, 0);
    lv_obj_set_flex_align(status9, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_t *label9 = lv_label_create(status9);
    lv_label_set_text(label9, "ios");
    lv_obj_set_style_text_font(label9, &lv_font_montserrat_16, 0);
    lv_obj_set_style_text_color(label9, lv_color_hex(0xFFFFFF), 0);
    LV_IMG_DECLARE(ios_set_300);
    lv_obj_t * img9 = lv_img_create(status9);
    lv_img_set_src(img9, &ios_set_300);
    lv_img_set_zoom(img9, 150);
    lv_obj_t * img91 = lv_img_create(status9);
    lv_img_set_src(img91, &ios_set_300);
    lv_img_set_zoom(img91, 150);

}

void lvgl_page_2()
{

}

void lvgl_page_3()
{

}

void lvgl_app_main(void)
{
    lvgl_page_1();
}
