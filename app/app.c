
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
    static lv_style_t cont_style;   // 容器的样式
    static lv_style_t obj_style;    // 容器中的对象的样式

    /* 设置容器的样式 */
    lv_style_init(&cont_style);
    lv_style_set_bg_opa(&cont_style, 0);
    lv_style_set_radius(&cont_style, 0);
    lv_style_set_border_width(&cont_style, 0);
    lv_style_set_bg_color(&cont_style, lv_palette_lighten(LV_PALETTE_RED, 10));

    /* 容器中的对象的样式 */
    lv_style_init(&obj_style);
    lv_style_set_radius(&obj_style, 0);
    lv_style_set_border_width(&obj_style, 0);

    // 顶层容器
    lv_obj_t *root = lv_obj_create(lv_scr_act());       // 创建容器
    lv_obj_set_size(root, LV_HOR_RES, LV_VER_RES);      // 设置大小
    lv_obj_set_style_pad_all(root, 0, 0);               // 设置边距
    lv_obj_set_layout(root, LV_LAYOUT_FLEX);            // 设置布局
    lv_obj_set_flex_flow(root, LV_FLEX_FLOW_COLUMN);    // 垂直布局
    lv_obj_center(root);                                // 居中
    lv_obj_add_style(root, &cont_style, 0);             // 样式

    // 上方的状态栏
    lv_obj_t *root1 = lv_obj_create(root);
    lv_obj_set_width(root1, LV_HOR_RES);
    lv_obj_set_style_pad_all(root1, 0, 0);
    lv_obj_set_layout(root1, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(root1, LV_FLEX_FLOW_ROW);      // 水平
    lv_obj_center(root1);
    lv_obj_set_flex_grow(root1, 1);                     // 比例
    lv_obj_add_style(root1, &cont_style, 0);


    // 下方的运动参数
    lv_obj_t *root2 = lv_obj_create(root);
    lv_obj_set_width(root2, LV_HOR_RES);
    lv_obj_set_style_pad_all(root2, 0, 0);
    lv_obj_set_layout(root2, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(root2, LV_FLEX_FLOW_ROW);      // 水平
    lv_obj_center(root2);
    lv_obj_set_flex_grow(root2, 2);
    lv_obj_add_style(root2, &cont_style, 0);


    // 时间图标
    lv_obj_t *status1 = lv_obj_create(root1);
    lv_obj_set_flex_flow(status1, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_style(status1, &cont_style, 0);
    LV_IMG_DECLARE(access_alarms_16dp_FFFFFF);
    lv_obj_t * img1 = lv_img_create(status1);
    lv_img_set_src(img1, &access_alarms_16dp_FFFFFF);
    lv_obj_t *label1 = lv_label_create(status1);
    lv_obj_align(label1, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(label1, "00:00");

    // 距离图标
    lv_obj_t *status2 = lv_obj_create(root1);
    lv_obj_set_flex_flow(status2, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_style(status2, &cont_style, 0);
    LV_IMG_DECLARE(access_alarms_16dp_FFFFFF);
    lv_obj_t * img2 = lv_img_create(status2);
    lv_img_set_src(img2, &access_alarms_16dp_FFFFFF);
    lv_obj_t *label2 = lv_label_create(status2);
    lv_label_set_text(label2, "00.0");

    // 卡路里图标
    lv_obj_t *status3 = lv_obj_create(root1);
    lv_obj_set_flex_flow(status3, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_style(status3, &cont_style, 0);
    LV_IMG_DECLARE(access_alarms_16dp_FFFFFF);
    lv_obj_t * img3 = lv_img_create(status3);
    lv_img_set_src(img3, &access_alarms_16dp_FFFFFF);
    lv_obj_t *label3 = lv_label_create(status3);
    lv_label_set_text(label3, "0000");

    // 速度图标
    lv_obj_t *status4 = lv_obj_create(root1);
    lv_obj_set_flex_flow(status4, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_style(status4, &cont_style, 0);
    LV_IMG_DECLARE(access_alarms_16dp_FFFFFF);
    lv_obj_t * img4 = lv_img_create(status4);
    lv_img_set_src(img4, &access_alarms_16dp_FFFFFF);
    lv_obj_t *label4 = lv_label_create(status4);
    lv_label_set_text(label4, "00.0");

    // 心率图标
    lv_obj_t *status5 = lv_obj_create(root1);
    lv_obj_set_flex_flow(status5, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_style(status5, &cont_style, 0);
    LV_IMG_DECLARE(access_alarms_16dp_FFFFFF);
    lv_obj_t * img5 = lv_img_create(status5);
    lv_img_set_src(img5, &access_alarms_16dp_FFFFFF);
    lv_obj_t *label5 = lv_label_create(status5);
    lv_label_set_text(label5, "0000");

    // 坡度图标
    lv_obj_t *status6 = lv_obj_create(root1);
    lv_obj_set_flex_flow(status6, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_style(status6, &cont_style, 0);
    LV_IMG_DECLARE(access_alarms_16dp_FFFFFF);
    lv_obj_t * img6 = lv_img_create(status6);
    lv_img_set_src(img6, &access_alarms_16dp_FFFFFF);
    lv_obj_t *label6 = lv_label_create(status6);
    lv_label_set_text(label6, "00");

    lv_obj_t * btn1 = lv_btn_create(root2);
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
