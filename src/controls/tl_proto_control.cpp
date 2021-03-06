/*************************************************************************/
/*  tl_proto_control.cpp                                                 */
/*************************************************************************/

#include "controls/tl_proto_control.hpp"

#ifdef GODOT_MODULE
#include "core/class_db.h"
#include "core/method_bind_ext.gen.inc"
#include "core/os/file_access.h"
#include "core/os/keyboard.h"
#include "core/os/os.h"
#include "servers/visual_server.h"
#define File _File
#else
#include <File.hpp>
#include <Image.hpp>
#include <InputEventKey.hpp>
#include <InputEventMouseButton.hpp>
#include <InputEventMouseMotion.hpp>
#include <MainLoop.hpp>
#include <OS.hpp>
#include <Texture.hpp>
#include <VisualServer.hpp>
#endif

/*************************************************************************/
/*  TLProtoControlSelection                                              */
/*************************************************************************/

TLProtoControlSelection::TLProtoControlSelection() {

#ifdef GODOT_MODULE
	_init();
#endif
}

TLProtoControlSelection::~TLProtoControlSelection() {
	//NOP
}

void TLProtoControlSelection::_init() {
	//NOP
}

int TLProtoControlSelection::get_caret_para() {

	return caret.p;
}

void TLProtoControlSelection::set_caret_para(int p_value) {

	if (caret.p != p_value) {
		caret.p = p_value;
		emit_signal("selection_changed");
	}
}

int TLProtoControlSelection::get_caret_offset() {

	return caret.o;
}

void TLProtoControlSelection::set_caret_offset(int p_value) {

	if (caret.o != p_value) {
		caret.o = p_value;
		emit_signal("selection_changed");
	}
}

int TLProtoControlSelection::get_start_para() {

	return start.p;
}

void TLProtoControlSelection::set_start_para(int p_value) {

	if (start.p != p_value) {
		start.p = p_value;
		emit_signal("selection_changed");
	}
}

int TLProtoControlSelection::get_start_offset() {

	return start.o;
}

void TLProtoControlSelection::set_start_offset(int p_value) {

	if (start.o != p_value) {
		start.o = p_value;
		emit_signal("selection_changed");
	}
}

int TLProtoControlSelection::get_end_para() {

	return end.p;
}

void TLProtoControlSelection::set_end_para(int p_value) {

	if (end.p != p_value) {
		end.p = p_value;
		emit_signal("selection_changed");
	}
}

int TLProtoControlSelection::get_end_offset() {

	return end.o;
}

void TLProtoControlSelection::set_end_offset(int p_value) {

	if (end.o != p_value) {
		end.o = p_value;
		emit_signal("selection_changed");
	}
}

#ifdef GODOT_MODULE

void TLProtoControlSelection::_bind_methods() {

	ClassDB::bind_method(D_METHOD("get_caret_para"), &TLProtoControlSelection::get_caret_para);
	ClassDB::bind_method(D_METHOD("set_caret_para", "value"), &TLProtoControlSelection::set_caret_para);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "caret_para"), "set_caret_para", "get_caret_para");

	ClassDB::bind_method(D_METHOD("get_caret_offset"), &TLProtoControlSelection::get_caret_offset);
	ClassDB::bind_method(D_METHOD("set_caret_offset", "value"), &TLProtoControlSelection::set_caret_offset);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "caret_offset"), "set_caret_offset", "get_caret_offset");

	ClassDB::bind_method(D_METHOD("get_start_para"), &TLProtoControlSelection::get_start_para);
	ClassDB::bind_method(D_METHOD("set_start_para", "value"), &TLProtoControlSelection::set_start_para);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "start_para"), "set_start_para", "get_start_para");

	ClassDB::bind_method(D_METHOD("get_start_offset"), &TLProtoControlSelection::get_start_offset);
	ClassDB::bind_method(D_METHOD("set_start_offset", "value"), &TLProtoControlSelection::set_start_offset);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "start_offset"), "set_start_offset", "get_start_offset");

	ClassDB::bind_method(D_METHOD("get_end_para"), &TLProtoControlSelection::get_end_para);
	ClassDB::bind_method(D_METHOD("set_end_para", "value"), &TLProtoControlSelection::set_end_para);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "end_para"), "set_end_para", "get_end_para");

	ClassDB::bind_method(D_METHOD("get_end_offset"), &TLProtoControlSelection::get_end_offset);
	ClassDB::bind_method(D_METHOD("set_end_offset", "value"), &TLProtoControlSelection::set_end_offset);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "end_offset"), "set_end_offset", "get_end_offset");

	ADD_SIGNAL(MethodInfo("selection_changed"));
}

#else

void TLProtoControlSelection::_register_methods() {

	register_method("get_caret_para", &TLProtoControlSelection::get_caret_para);
	register_method("set_caret_para", &TLProtoControlSelection::set_caret_para);
	register_property<TLProtoControlSelection, int>("caret_para", &TLProtoControlSelection::set_caret_para, &TLProtoControlSelection::get_caret_para, 0);

	register_method("get_caret_offset", &TLProtoControlSelection::get_caret_offset);
	register_method("set_caret_offset", &TLProtoControlSelection::set_caret_offset);
	register_property<TLProtoControlSelection, int>("caret_offset", &TLProtoControlSelection::set_caret_offset, &TLProtoControlSelection::get_caret_offset, 0);

	register_method("get_start_para", &TLProtoControlSelection::get_start_para);
	register_method("set_start_para", &TLProtoControlSelection::set_start_para);
	register_property<TLProtoControlSelection, int>("start_para", &TLProtoControlSelection::set_start_para, &TLProtoControlSelection::get_start_para, 0);

	register_method("get_start_offset", &TLProtoControlSelection::get_start_offset);
	register_method("set_start_offset", &TLProtoControlSelection::set_start_offset);
	register_property<TLProtoControlSelection, int>("start_offset", &TLProtoControlSelection::set_start_offset, &TLProtoControlSelection::get_start_offset, 0);

	register_method("get_end_para", &TLProtoControlSelection::get_end_para);
	register_method("set_end_para", &TLProtoControlSelection::set_end_para);
	register_property<TLProtoControlSelection, int>("end_para", &TLProtoControlSelection::set_end_para, &TLProtoControlSelection::get_end_para, 0);

	register_method("get_end_offset", &TLProtoControlSelection::get_end_offset);
	register_method("set_end_offset", &TLProtoControlSelection::set_end_offset);
	register_property<TLProtoControlSelection, int>("end_offset", &TLProtoControlSelection::set_end_offset, &TLProtoControlSelection::get_end_offset, 0);

	register_signal<TLProtoControlSelection>("selection_changed");
}

#endif

/*************************************************************************/
/*  TLProtoControl                                                       */
/*************************************************************************/

TLProtoControl::TLProtoControl() {

#ifdef GODOT_MODULE
	_init();
#endif
}

TLProtoControl::~TLProtoControl() {

	for (int i = 0; i < paragraphs.size(); i++) {
		paragraphs[i]->disconnect("paragraph_changed", this, "_update_ctx_rect");
	}
}

void TLProtoControl::_init() {

	set_focus_mode(FOCUS_ALL);

	para_spacing = 3.0f;

	margin[MARGIN_TOP] = 4.0f;
	margin[MARGIN_BOTTOM] = 2.0f;
	margin[MARGIN_LEFT] = 2.0f;
	margin[MARGIN_RIGHT] = 2.0f;

	cursor_color = Color(0, 0, 1);
	selection_color = Color(0, 0.5, 0.5, 0.5);
	ime_selection_color = Color(0, 0, 0.5, 0.2);
	bg_color = Color(1, 1, 1, 0.5);

	content_size = Size2(0, 0);

	last_inp_dir = TEXT_DIRECTION_LTR;

	ime_cursor = 0;
	ime_selection_len = 0;
	ime_len = 0;

	in_focus = false;
	readonly = false;
	selectable = true;

	Ref<TLShapedParagraph> new_para;
#ifdef GODOT_MODULE
	new_para.instance();
#else
	new_para = Ref<TLShapedParagraph>::__internal_constructor(TLShapedParagraph::_new());
#endif
	new_para->connect("paragraph_changed", this, "_update_ctx_rect");
	paragraphs.push_back(new_para);

#ifdef GODOT_MODULE
	selection.instance();
#else
	selection = Ref<TLProtoControlSelection>::__internal_constructor(TLProtoControlSelection::_new());
#endif
	selection->connect("selection_changed", this, "_update_ctx_rect");
};

void TLProtoControl::clear() {

	for (int i = 0; i < paragraphs.size(); i++) {
		paragraphs[i]->disconnect("paragraph_changed", this, "_update_ctx_rect");
	}
	paragraphs.clear();
	if (ime_temp_para.is_valid())
		ime_temp_para->disconnect("paragraph_changed", this, "_update_ctx_rect");
	ime_temp_para = Ref<TLShapedParagraph>();

	selection->caret.p = 0;
	selection->caret.o = 0;
	selection->start = selection->caret;
	selection->end = selection->caret;

	Ref<TLShapedParagraph> new_para;
#ifdef GODOT_MODULE
	new_para.instance();
#else
	new_para = Ref<TLShapedParagraph>::__internal_constructor(TLShapedParagraph::_new());
#endif
	new_para->connect("paragraph_changed", this, "_update_ctx_rect");
	paragraphs.push_back(new_para);
}

void TLProtoControl::_update_ctx_rect() {

	content_size = Size2(0, 0);
	for (int i = 0; i < paragraphs.size(); i++) {
		if (ime_temp_para.is_valid()) {
			if (i == selection->start.p) {
				Size2 _size = ime_temp_para->get_size();
				content_size.height += _size.y + para_spacing;
				content_size.width = MAX(content_size.width, _size.x);
				continue;
			} else if ((i > selection->start.p) && (i <= selection->end.p)) {
				continue;
			}
		}
		Size2 _size = paragraphs[i]->get_size();
		content_size.height += _size.y + para_spacing;
		content_size.width = MAX(content_size.width, _size.x);
	}
	content_size.height += margin[MARGIN_TOP] + margin[MARGIN_BOTTOM];
	content_size.width += margin[MARGIN_LEFT] + margin[MARGIN_RIGHT];

	minimum_size_changed();
	update();
}

Size2 TLProtoControl::get_minimum_size() const {

	return content_size;
}

int TLProtoControl::get_paragraphs() {

	return paragraphs.size();
}

Ref<TLShapedParagraph> TLProtoControl::get_paragraph(int p_index) const {

	if ((p_index < 0) || (p_index >= paragraphs.size()))
		return Ref<TLShapedParagraph>();

	return paragraphs[p_index];
}

void TLProtoControl::set_paragraph(Ref<TLShapedParagraph> p_para, int p_index) {

	if ((p_index < 0) || (p_index >= paragraphs.size()))
		return;

	paragraphs[p_index]->disconnect("paragraph_changed", this, "_update_ctx_rect");
	paragraphs[p_index] = p_para;
	paragraphs[p_index]->connect("paragraph_changed", this, "_update_ctx_rect");

	_update_ctx_rect();
}

int TLProtoControl::insert_paragraph(Ref<TLShapedParagraph> p_para, int p_index) {

	if ((p_index < 0) || (p_index > paragraphs.size()))
		return -1;

	int index = (p_index > 0) ? p_index - 1 : p_index;

	Ref<TLShapedParagraph> new_para;
	if (p_para.is_null()) {
#ifdef GODOT_MODULE
		new_para.instance();
#else
		new_para = Ref<TLShapedParagraph>::__internal_constructor(TLShapedParagraph::_new());
#endif
		new_para->copy_properties(paragraphs[index]);
	} else {
		new_para = p_para;
	}
	new_para->connect("paragraph_changed", this, "_update_ctx_rect");

	_fix_selection();
	_update_ctx_rect();
#ifdef GODOT_MODULE
	_change_notify();
#endif

	return std::distance(paragraphs.begin(), paragraphs.insert(paragraphs.begin() + p_index, new_para));
}

void TLProtoControl::remove_paragraph(int p_index) {

	if ((p_index < 0) || (p_index >= paragraphs.size()))
		return;

	paragraphs[p_index]->disconnect("paragraph_changed", this, "_update_ctx_rect");
	paragraphs.erase(paragraphs.begin() + p_index);
	_fix_selection();
	_update_ctx_rect();
#ifdef GODOT_MODULE
	_change_notify();
#endif

	emit_signal("cursor_changed");
}

void TLProtoControl::_fix_selection() {

	if (selection->start.p < 0) selection->start.p = 0;
	if (selection->start.p >= paragraphs.size()) selection->start.p = paragraphs.size() - 1;

	if (selection->start.o < 0) selection->start.o = 0;
	if (selection->start.o >= paragraphs[selection->start.p]->get_string()->length()) selection->start.o = paragraphs[selection->start.p]->get_string()->length();

	if (selection->end.p < 0) selection->end.p = 0;
	if (selection->end.p >= paragraphs.size()) selection->end.p = paragraphs.size() - 1;

	if (selection->end.o < 0) selection->end.o = 0;
	if (selection->end.o >= paragraphs[selection->end.p]->get_string()->length()) selection->end.o = paragraphs[selection->end.p]->get_string()->length();

	if (selection->caret.p < 0) selection->caret.p = 0;
	if (selection->caret.p >= paragraphs.size()) selection->caret.p = paragraphs.size() - 1;

	if (selection->caret.o < 0) selection->caret.o = 0;
	if (selection->caret.o >= paragraphs[selection->caret.p]->get_string()->length()) selection->caret.o = paragraphs[selection->caret.p]->get_string()->length();
}

Ref<TLProtoControlSelection> TLProtoControl::get_selection() const {

	return selection;
}

void TLProtoControl::set_selection(Ref<TLProtoControlSelection> p_selection) {

	selection->disconnect("selection_changed", this, "_update_ctx_rect");
	selection = p_selection;
	_fix_selection();
	selection->connect("selection_changed", this, "_update_ctx_rect");

	emit_signal("cursor_changed");
}

void TLProtoControl::add_attribute(Ref<TLProtoControlSelection> p_selection, int p_attribute, Variant p_value) {

	for (int i = p_selection->start.p; i <= p_selection->end.p; i++) {
		int _start = (i == p_selection->start.p) ? p_selection->start.o : 0;
		int _end = (i == p_selection->end.p) ? p_selection->end.o : paragraphs[i]->get_string()->length();
		paragraphs[i]->get_string()->add_attribute(p_attribute, p_value, _start, _end);
	}
}

void TLProtoControl::remove_attribute(Ref<TLProtoControlSelection> p_selection, int p_attribute) {

	for (int i = p_selection->start.p; i <= p_selection->end.p; i++) {
		int _start = (i == p_selection->start.p) ? p_selection->start.o : 0;
		int _end = (i == p_selection->end.p) ? p_selection->end.o : paragraphs[i]->get_string()->length();
		paragraphs[i]->get_string()->remove_attribute(p_attribute, _start, _end);
	}
}

void TLProtoControl::remove_attributes(Ref<TLProtoControlSelection> p_selection) {

	for (int i = p_selection->start.p; i <= p_selection->end.p; i++) {
		int _start = (i == p_selection->start.p) ? p_selection->start.o : 0;
		int _end = (i == p_selection->end.p) ? p_selection->end.o : paragraphs[i]->get_string()->length();
		paragraphs[i]->get_string()->remove_attributes(_start, _end);
	}
}

void TLProtoControl::set_paragraph_width(Ref<TLProtoControlSelection> p_selection, float p_width) {

	for (int i = p_selection->start.p; i <= p_selection->end.p; i++) {
		paragraphs[i]->set_width(p_width);
	}
}

void TLProtoControl::set_paragraph_indent(Ref<TLProtoControlSelection> p_selection, float p_indent) {

	for (int i = p_selection->start.p; i <= p_selection->end.p; i++) {
		paragraphs[i]->set_indent(p_indent);
	}
}

void TLProtoControl::set_paragraph_back_color(Ref<TLProtoControlSelection> p_selection, Color p_bcolor) {

	for (int i = p_selection->start.p; i <= p_selection->end.p; i++) {
		paragraphs[i]->set_back_color(p_bcolor);
	}
}

void TLProtoControl::set_paragraph_line_spacing(Ref<TLProtoControlSelection> p_selection, float p_line_spacing) {

	for (int i = p_selection->start.p; i <= p_selection->end.p; i++) {
		paragraphs[i]->set_line_spacing(p_line_spacing);
	}
}

void TLProtoControl::set_paragraph_brk_flags(Ref<TLProtoControlSelection> p_selection, int p_flags) {

	for (int i = p_selection->start.p; i <= p_selection->end.p; i++) {
		paragraphs[i]->set_brk_flags(p_flags);
	}
}

void TLProtoControl::set_paragraph_jst_flags(Ref<TLProtoControlSelection> p_selection, int p_flags) {

	for (int i = p_selection->start.p; i <= p_selection->end.p; i++) {
		paragraphs[i]->set_jst_flags(p_flags);
	}
}

void TLProtoControl::set_paragraph_halign(Ref<TLProtoControlSelection> p_selection, int p_halign) {

	for (int i = p_selection->start.p; i <= p_selection->end.p; i++) {
		paragraphs[i]->set_halign(p_halign);
	}
}

Point2 TLProtoControl::get_caret_position() {

	return caret_pos;
}

void TLProtoControl::_hit_test(Point2 p_position, bool p_shift) {

	float y_ofs = margin[MARGIN_TOP];
	if (p_position.y < margin[MARGIN_TOP]) {
		return;
	}
	for (int i = 0; i < paragraphs.size(); i++) {
		if (paragraphs[i]->get_lines() == 0) {
			if ((p_position.y >= y_ofs) && (p_position.y < y_ofs + paragraphs[i]->get_string()->get_height() * paragraphs[i]->get_line_spacing())) {
				TLProtoControlSelection::Cursor mod = selection->caret;
				TLProtoControlSelection::Cursor ret = TLProtoControlSelection::Cursor(i, 0);
				selection->caret = ret;
				if (!p_shift) {
					selection->start = ret;
					selection->end = ret;
				} else if (mod == selection->start) {
					selection->start = ret;
				} else {
					selection->end = ret;
				}
				if (selection->start > selection->end) {
					TLProtoControlSelection::Cursor _sw = selection->start;
					selection->start = selection->end;
					selection->end = _sw;
				}
				return;
			}
			y_ofs += paragraphs[i]->get_string()->get_height() * paragraphs[i]->get_line_spacing();
		} else {
			std::vector<int> bounds = paragraphs[i]->get_line_bounds();
			for (int j = 0; j < paragraphs[i]->get_lines(); j++) {
				float x_ofs = margin[MARGIN_LEFT];
				if (paragraphs[i]->get_width() > 0) {
					if (paragraphs[i]->get_halign() == PARA_HALIGN_RIGHT) {
						x_ofs = (paragraphs[i]->get_width() - paragraphs[i]->get_line(j)->get_width());
					} else if (paragraphs[i]->get_halign() == PARA_HALIGN_CENTER) {
						x_ofs = ((paragraphs[i]->get_width() - paragraphs[i]->get_line(j)->get_width()) / 2);
					}
				}
				if (paragraphs[i]->get_line(j).is_valid()) {
					if (p_position.y >= y_ofs && p_position.y < y_ofs + paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing()) {
						TLProtoControlSelection::Cursor mod = selection->caret;
						TLProtoControlSelection::Cursor ret = TLProtoControlSelection::Cursor(i, paragraphs[i]->get_string()->next_safe_bound(((j > 0) ? bounds[j - 1] : 0) + paragraphs[i]->get_line(j)->hit_test(p_position.x - paragraphs[i]->get_indent() - x_ofs)));

						selection->caret = ret;
						if (!p_shift) {
							selection->start = ret;
							selection->end = ret;
						} else if (mod == selection->start) {
							selection->start = ret;
						} else {
							selection->end = ret;
						}
						if (selection->start > selection->end) {
							TLProtoControlSelection::Cursor _sw = selection->start;
							selection->start = selection->end;
							selection->end = _sw;
						}
						return;
					}
					y_ofs += paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing();
				}
			}
		}
		y_ofs += para_spacing;
	}
}

Rect2 TLProtoControl::get_cluster_rect_hit_test(Point2 p_position) {

	float y_ofs = margin[MARGIN_TOP];
	if (p_position.y < margin[MARGIN_TOP]) {
		return Rect2();
	}
	for (int i = 0; i < paragraphs.size(); i++) {
		if (paragraphs[i]->get_lines() == 0) {
			return Rect2();
		} else {
			std::vector<int> bounds = paragraphs[i]->get_line_bounds();
			for (int j = 0; j < paragraphs[i]->get_lines(); j++) {
				float x_ofs = margin[MARGIN_LEFT];
				if (paragraphs[i]->get_width() > 0) {
					if (paragraphs[i]->get_halign() == PARA_HALIGN_RIGHT) {
						x_ofs = (paragraphs[i]->get_width() - paragraphs[i]->get_line(j)->get_width());
					} else if (paragraphs[i]->get_halign() == PARA_HALIGN_CENTER) {
						x_ofs = ((paragraphs[i]->get_width() - paragraphs[i]->get_line(j)->get_width()) / 2);
					}
				}
				if (paragraphs[i]->get_line(j).is_valid()) {
					if (p_position.y >= y_ofs && p_position.y < y_ofs + paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing()) {
						int64_t cl = paragraphs[i]->get_line(j)->hit_test_cluster(p_position.x - paragraphs[i]->get_indent() - x_ofs);

						Rect2 x = paragraphs[i]->get_line(j)->get_cluster_rect(cl);
						x.position.x += paragraphs[i]->get_indent() + x_ofs;
						x.position.y += y_ofs + paragraphs[i]->get_line(j)->get_ascent();
						return x;
					}
					y_ofs += paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing();
				}
			}
		}
		y_ofs += para_spacing;
	}
	return Rect2();
}

Array TLProtoControl::get_cluster_glyphs_hit_test(Point2 p_position) {

	Array glyphs;
	float y_ofs = margin[MARGIN_TOP];
	if (p_position.y < margin[MARGIN_TOP]) {
		return glyphs;
	}
	for (int i = 0; i < paragraphs.size(); i++) {
		if (paragraphs[i]->get_lines() == 0) {
			return glyphs;
		} else {
			std::vector<int> bounds = paragraphs[i]->get_line_bounds();
			for (int j = 0; j < paragraphs[i]->get_lines(); j++) {
				float x_ofs = margin[MARGIN_LEFT];
				if (paragraphs[i]->get_width() > 0) {
					if (paragraphs[i]->get_halign() == PARA_HALIGN_RIGHT) {
						x_ofs = (paragraphs[i]->get_width() - paragraphs[i]->get_line(j)->get_width());
					} else if (paragraphs[i]->get_halign() == PARA_HALIGN_CENTER) {
						x_ofs = ((paragraphs[i]->get_width() - paragraphs[i]->get_line(j)->get_width()) / 2);
					}
				}
				if (paragraphs[i]->get_line(j).is_valid()) {
					if (p_position.y >= y_ofs && p_position.y < y_ofs + paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing()) {
						int64_t cl = paragraphs[i]->get_line(j)->hit_test_cluster(p_position.x - paragraphs[i]->get_indent() - x_ofs);

						int c = paragraphs[i]->get_line(j)->get_cluster_glyphs(cl);
						for (int k = 0; k < c; k++) {
							glyphs.push_back(paragraphs[i]->get_line(j)->get_cluster_face(cl));
							glyphs.push_back(paragraphs[i]->get_line(j)->get_cluster_face_size(cl));
							glyphs.push_back(paragraphs[i]->get_line(j)->get_cluster_ascent(cl));
							glyphs.push_back(paragraphs[i]->get_line(j)->get_cluster_descent(cl));
							glyphs.push_back(paragraphs[i]->get_line(j)->get_cluster_glyph(cl, k));
							glyphs.push_back(paragraphs[i]->get_line(j)->get_cluster_glyph_offset(cl, k));
							glyphs.push_back(paragraphs[i]->get_line(j)->get_cluster_glyph_advance(cl, k));
						}

						return glyphs;
					}
					y_ofs += paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing();
				}
			}
		}
		y_ofs += para_spacing;
	}
	return glyphs;
}

String TLProtoControl::get_cluster_debug_info_hit_test(Point2 p_position) {

	float y_ofs = margin[MARGIN_TOP];
	if (p_position.y < margin[MARGIN_TOP]) {
		return String();
	}
	for (int i = 0; i < paragraphs.size(); i++) {
		if (paragraphs[i]->get_lines() == 0) {
			return String();
		} else {
			std::vector<int> bounds = paragraphs[i]->get_line_bounds();
			for (int j = 0; j < paragraphs[i]->get_lines(); j++) {
				float x_ofs = margin[MARGIN_LEFT];
				if (paragraphs[i]->get_width() > 0) {
					if (paragraphs[i]->get_halign() == PARA_HALIGN_RIGHT) {
						x_ofs = (paragraphs[i]->get_width() - paragraphs[i]->get_line(j)->get_width());
					} else if (paragraphs[i]->get_halign() == PARA_HALIGN_CENTER) {
						x_ofs = ((paragraphs[i]->get_width() - paragraphs[i]->get_line(j)->get_width()) / 2);
					}
				}
				if (paragraphs[i]->get_line(j).is_valid()) {
					if (p_position.y >= y_ofs && p_position.y < y_ofs + paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing()) {
						int64_t cl = paragraphs[i]->get_line(j)->hit_test_cluster(p_position.x - paragraphs[i]->get_indent() - x_ofs);

						String info = paragraphs[i]->get_line(j)->get_cluster_debug_info(cl);
						info += String("Para: ") + String::num_int64(i) + String(" [");
						std::vector<int> lines = paragraphs[i]->get_line_bounds();
						for (int k = 0; k < lines.size(); k++) {
							info += String::num_int64(lines[k]) + String(",");
						}
						info += String("]; ");
						info += String("Line: ") + String::num_int64(j) + String(" (") + String::num_int64(paragraphs[i]->get_line(j)->length()) + String("); ");
						info += String("Pos: ") + String::num_int64(paragraphs[i]->get_line(j)->get_cluster_start(cl)) + String("/") + String::num_int64(paragraphs[i]->get_line(j)->get_cluster_end(cl)) + String("; ");
						info += String("Glyphs: [");
						for (int k = 0; k < paragraphs[i]->get_line(j)->get_cluster_glyphs(cl); k++) {
							info += String::num_int64(paragraphs[i]->get_line(j)->get_cluster_glyph(cl, k)) + String(",");
						}
						info += String("]");

						return info;
					}
					y_ofs += paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing();
				}
			}
		}
		y_ofs += para_spacing;
	}
	return String();
}

void TLProtoControl::_change_selection(bool p_shift, TLProtoControl::AdvDir p_dir, TextDirection p_last_imp_dir) {

	if ((!p_shift) && (selection->start != selection->end)) {
		if (p_dir % 2 != 0) {
			selection->caret = selection->start;
			selection->end = selection->start;
		} else {
			selection->caret = selection->end;
			selection->start = selection->end;
		}
		return;
	}

	TLProtoControlSelection::Cursor mod = selection->caret;
	TLProtoControlSelection::Cursor ret = mod;

	switch (p_dir) {
		case FWD_CHAR: {
			if (mod.o < paragraphs[mod.p]->get_string()->length()) {
				ret.o = paragraphs[mod.p]->get_string()->next_safe_bound(mod.o + 1);
			} else if (mod.p < paragraphs.size() - 1) {
				ret.p++;
				ret.o = 0;
			}
		} break;
		case REV_CHAR: {
			if (mod.o > 0) {
				ret.o = paragraphs[mod.p]->get_string()->prev_safe_bound(mod.o - 1);
			} else if (mod.p > 0) {
				ret.p--;
				ret.o = paragraphs[ret.p]->get_string()->length();
			}
		} break;
		case FWD_WORD: {
			if (mod.o == paragraphs[ret.p]->get_string()->length()) {
				if (mod.p < paragraphs.size() - 1) {
					ret.p++;
					ret.o = 0;
				}
				break;
			}
			bool found_wb = false;
			std::vector<int> bounds = paragraphs[mod.p]->get_word_bounds();
			for (int i = 0; i < bounds.size(); i++) {
				if (bounds[i] > mod.o) {
					ret.o = bounds[i];
					found_wb = true;
					break;
				}
			}
			if (!found_wb) {
				ret.o = paragraphs[ret.p]->get_string()->length();
			}
		} break;
		case REV_WORD: {
			if (mod.o == 0) {
				if (mod.p > 0) {
					ret.p--;
					ret.o = paragraphs[ret.p]->get_string()->length();
				}
				break;
			}
			bool found_wb = false;
			std::vector<int> bounds = paragraphs[mod.p]->get_word_bounds();
			for (int i = bounds.size() - 1; i >= 0; i--) {
				if (bounds[i] < mod.o) {
					ret.o = bounds[i];
					found_wb = true;
					break;
				}
			}
			if (!found_wb) {
				ret.o = 0;
			}
		} break;
		case FWD_LINE: {
			if (paragraphs[mod.p]->get_string()->length() == 0) {
				if (mod.p < paragraphs.size() - 1) {
					ret.p++;
					ret.o = 0;
				}
				break;
			}
			if ((mod.p < paragraphs.size() - 1) && (paragraphs[mod.p + 1]->get_string()->length() == 0)) {
				ret.p++;
				ret.o = 0;
				break;
			}
			int line = -1;
			int l_start = 0;
			int n_para = mod.p;
			int n_line = -1;
			std::vector<int> bounds = paragraphs[mod.p]->get_line_bounds();
			for (int i = 0; i < bounds.size(); i++) {
				if (i == bounds.size() - 1) {
					if ((mod.o >= l_start) && (mod.o <= bounds[i])) {
						line = i;
						n_line = i + 1;
						break;
					}
				} else {
					if ((mod.o >= l_start) && (mod.o < bounds[i])) {
						line = i;
						n_line = i + 1;
						break;
					}
				}
				l_start = bounds[i];
			}
			if (line == bounds.size() - 1) {
				if (n_para == paragraphs.size() - 1) {
					break;
				}
				n_para++;
				if (paragraphs[n_para]->get_line_bounds().size() == 0) {
					break;
				}
				n_line = 0;
			}
			if (line == -1) {
				break;
			}
			std::vector<float> curof = paragraphs[mod.p]->get_line(line)->get_cursor_positions(mod.o - l_start, p_last_imp_dir);
			if (curof.size() > 0) {
				int new_l_start = (n_line > 0) ? paragraphs[n_para]->get_line_bounds()[n_line - 1] : 0;
				float distance = FLT_MAX;
				for (int i = 0; i <= paragraphs[n_para]->get_line(n_line)->length(); i++) {
					std::vector<float> lof = paragraphs[n_para]->get_line(n_line)->get_cursor_positions(i, p_last_imp_dir);
					if (lof.size() > 0) {
						if (abs(lof[0] - curof[0]) < distance) {
							distance = abs(lof[0] - curof[0]);
							ret.p = n_para;
							ret.o = new_l_start + i;
						}
					}
				}
			}
		} break;
		case REV_LINE: {
			if (paragraphs[mod.p]->get_string()->length() == 0) {
				if (mod.p > 0) {
					ret.p--;
					ret.o = 0;
				}
				break;
			}
			if ((mod.p > 0) && (paragraphs[mod.p - 1]->get_string()->length() == 0)) {
				ret.p--;
				ret.o = 0;
				break;
			}
			int line = -1;
			int l_start = 0;
			int n_para = mod.p;
			int n_line = -1;
			std::vector<int> bounds = paragraphs[mod.p]->get_line_bounds();
			for (int i = 0; i < bounds.size(); i++) {
				if (i == bounds.size() - 1) {
					if ((mod.o >= l_start) && (mod.o <= bounds[i])) {
						line = i;
						n_line = i - 1;
						break;
					}
				} else {
					if ((mod.o >= l_start) && (mod.o < bounds[i])) {
						line = i;
						n_line = i - 1;
						break;
					}
				}
				l_start = bounds[i];
			}
			if (line == 0) {
				if (n_para == 0) {
					break;
				}
				n_para--;
				if (paragraphs[n_para]->get_line_bounds().size() == 0) {
					break;
				}
				n_line = paragraphs[n_para]->get_line_bounds().size() - 1;
			}
			if (line == -1) {
				break;
			}
			std::vector<float> curof = paragraphs[mod.p]->get_line(line)->get_cursor_positions(mod.o - l_start, p_last_imp_dir);
			if (curof.size() > 0) {
				int new_l_start = (n_line > 0) ? paragraphs[n_para]->get_line_bounds()[n_line - 1] : 0;
				float distance = FLT_MAX;
				for (int i = 0; i <= paragraphs[n_para]->get_line(n_line)->length(); i++) {
					std::vector<float> lof = paragraphs[n_para]->get_line(n_line)->get_cursor_positions(i, p_last_imp_dir);
					if (lof.size() > 0) {
						if (abs(lof[0] - curof[0]) < distance) {
							distance = abs(lof[0] - curof[0]);
							ret.p = n_para;
							ret.o = new_l_start + i;
						}
					}
				}
			}
		} break;
		case PARA_START: {
			if (mod.o == 0) {
				if (mod.p > 0) {
					ret.p--;
					ret.o = paragraphs[ret.p]->get_string()->length();
				}
			} else {
				ret.o = 0;
			}
		} break;
		case PARA_END: {
			if (mod.o == paragraphs[ret.p]->get_string()->length()) {
				if (mod.p < paragraphs.size() - 1) {
					ret.p++;
					ret.o = 0;
				}
			} else {
				ret.o = paragraphs[ret.p]->get_string()->length();
			}
		} break;
		case LINE_START: {
			int l_start = 0;
			std::vector<int> bounds = paragraphs[mod.p]->get_line_bounds();
			for (int i = 0; i < bounds.size(); i++) {
				if (i == bounds.size() - 1) {
					if ((mod.o >= l_start) && (mod.o <= bounds[i])) {
						ret.o = l_start;
						break;
					}
				} else {
					if ((mod.o >= l_start) && (mod.o < bounds[i])) {
						ret.o = l_start;
						break;
					}
				}
				l_start = bounds[i];
			}
		} break;
		case LINE_END: {
			int l_start = 0;
			std::vector<int> bounds = paragraphs[mod.p]->get_line_bounds();
			for (int i = 0; i < bounds.size(); i++) {
				if (i == bounds.size() - 1) {
					if ((mod.o >= l_start) && (mod.o <= bounds[i])) {
						ret.o = bounds[i];
						break;
					}
				} else {
					if ((mod.o >= l_start) && (mod.o < bounds[i])) {
						ret.o = bounds[i] - 1;
						break;
					}
				}
				l_start = bounds[i];
			}
		} break;
		case TEXT_START: {
			ret.p = 0;
			ret.o = 0;
		} break;
		case TEXT_END: {
			ret.p = paragraphs.size() - 1;
			ret.o = paragraphs[ret.p]->get_string()->length();
		} break;
	}

	selection->caret = ret;
	if (!p_shift) {
		selection->start = ret;
		selection->end = ret;
	} else if (mod == selection->start) {
		selection->start = ret;
	} else {
		selection->end = ret;
	}
	if (selection->start > selection->end) {
		TLProtoControlSelection::Cursor _sw = selection->start;
		selection->start = selection->end;
		selection->end = _sw;
	}
}

void TLProtoControl::replace_text(Ref<TLProtoControlSelection> p_selection, const String p_text) {

	if (p_selection->start.p != p_selection->end.p) {
		int first_para = p_selection->start.p;
		int last_para = p_selection->end.p;

		int offset = paragraphs[first_para]->get_string()->length();
		for (int i = first_para + 1; i <= last_para; i++) {
			paragraphs[first_para]->get_string()->add_sstring(paragraphs[first_para + 1]->get_string());
			if (i != last_para) offset += paragraphs[first_para + 1]->get_string()->length();
			paragraphs[first_para + 1]->disconnect("paragraph_changed", this, "_update_ctx_rect");
			paragraphs.erase(paragraphs.begin() + first_para + 1);
		}

		p_selection->end.p = first_para;
		p_selection->end.o += offset;
	}

	int _len = paragraphs[p_selection->start.p]->get_string()->length(); //old offset
	paragraphs[p_selection->start.p]->get_string()->replace_text(p_selection->start.o, p_selection->end.o, p_text);
	p_selection->end.o += (paragraphs[p_selection->start.p]->get_string()->length() - _len);

	p_selection->start = p_selection->end;
	p_selection->caret = p_selection->end;

	selection->disconnect("selection_changed", this, "_update_ctx_rect");
	selection = p_selection;
	selection->connect("selection_changed", this, "_update_ctx_rect");

	emit_signal("cursor_changed");
	update();
}

void TLProtoControl::replace_utf8(Ref<TLProtoControlSelection> p_selection, const PoolByteArray p_text) {

	if (p_selection->start.p != p_selection->end.p) {
		int first_para = p_selection->start.p;
		int last_para = p_selection->end.p;

		int offset = paragraphs[first_para]->get_string()->length();
		for (int i = first_para + 1; i <= last_para; i++) {
			paragraphs[first_para]->get_string()->add_sstring(paragraphs[first_para + 1]->get_string());
			if (i != last_para) offset += paragraphs[first_para + 1]->get_string()->length();
			paragraphs[first_para + 1]->disconnect("paragraph_changed", this, "_update_ctx_rect");
			paragraphs.erase(paragraphs.begin() + first_para + 1);
		}

		p_selection->end.p = first_para;
		p_selection->end.o += offset;
	}

	int _len = paragraphs[p_selection->start.p]->get_string()->length(); //old offset
	paragraphs[p_selection->start.p]->get_string()->replace_utf8(p_selection->start.o, p_selection->end.o, p_text);
	p_selection->end.o += (paragraphs[p_selection->start.p]->get_string()->length() - _len);

	p_selection->start = p_selection->end;
	p_selection->caret = p_selection->end;

	selection->disconnect("selection_changed", this, "_update_ctx_rect");
	selection = p_selection;
	selection->connect("selection_changed", this, "_update_ctx_rect");

	emit_signal("cursor_changed");
	update();
}

void TLProtoControl::replace_utf16(Ref<TLProtoControlSelection> p_selection, const PoolByteArray p_text) {

	if (p_selection->start.p != p_selection->end.p) {
		int first_para = p_selection->start.p;
		int last_para = p_selection->end.p;

		int offset = paragraphs[first_para]->get_string()->length();
		for (int i = first_para + 1; i <= last_para; i++) {
			paragraphs[first_para]->get_string()->add_sstring(paragraphs[first_para + 1]->get_string());
			if (i != last_para) offset += paragraphs[first_para + 1]->get_string()->length();
			paragraphs[first_para + 1]->disconnect("paragraph_changed", this, "_update_ctx_rect");
			paragraphs.erase(paragraphs.begin() + first_para + 1);
		}

		p_selection->end.p = first_para;
		p_selection->end.o += offset;
	}

	int _len = paragraphs[p_selection->start.p]->get_string()->length(); //old offset
	paragraphs[p_selection->start.p]->get_string()->replace_utf16(p_selection->start.o, p_selection->end.o, p_text);
	p_selection->end.o += (paragraphs[p_selection->start.p]->get_string()->length() - _len);

	p_selection->start = p_selection->end;
	p_selection->caret = p_selection->end;

	selection->disconnect("selection_changed", this, "_update_ctx_rect");
	selection = p_selection;
	selection->connect("selection_changed", this, "_update_ctx_rect");

	emit_signal("cursor_changed");
	update();
}

void TLProtoControl::replace_utf32(Ref<TLProtoControlSelection> p_selection, const PoolByteArray p_text) {

	if (p_selection->start.p != p_selection->end.p) {
		int first_para = p_selection->start.p;
		int last_para = p_selection->end.p;

		int offset = paragraphs[first_para]->get_string()->length();
		for (int i = first_para + 1; i <= last_para; i++) {
			paragraphs[first_para]->get_string()->add_sstring(paragraphs[first_para + 1]->get_string());
			if (i != last_para) offset += paragraphs[first_para + 1]->get_string()->length();
			paragraphs[first_para + 1]->disconnect("paragraph_changed", this, "_update_ctx_rect");
			paragraphs.erase(paragraphs.begin() + first_para + 1);
		}

		p_selection->end.p = first_para;
		p_selection->end.o += offset;
	}

	int _len = paragraphs[p_selection->start.p]->get_string()->length(); //old offset
	paragraphs[p_selection->start.p]->get_string()->replace_utf32(p_selection->start.o, p_selection->end.o, p_text);
	p_selection->end.o += (paragraphs[p_selection->start.p]->get_string()->length() - _len);

	p_selection->start = p_selection->end;
	p_selection->caret = p_selection->end;

	selection->disconnect("selection_changed", this, "_update_ctx_rect");
	selection = p_selection;
	selection->connect("selection_changed", this, "_update_ctx_rect");

	emit_signal("cursor_changed");
	update();
}

void TLProtoControl::replace_sstring(Ref<TLProtoControlSelection> p_selection, Ref<TLShapedString> p_text) {

	if (p_selection->start.p != p_selection->end.p) {
		int first_para = p_selection->start.p;
		int last_para = p_selection->end.p;

		int offset = paragraphs[first_para]->get_string()->length();
		for (int i = first_para + 1; i <= last_para; i++) {
			paragraphs[first_para]->get_string()->add_sstring(paragraphs[first_para + 1]->get_string());
			if (i != last_para) offset += paragraphs[first_para + 1]->get_string()->length();
			paragraphs[first_para + 1]->disconnect("paragraph_changed", this, "_update_ctx_rect");
			paragraphs.erase(paragraphs.begin() + first_para + 1);
		}

		p_selection->end.p = first_para;
		p_selection->end.o += offset;
	}

	int _len = paragraphs[p_selection->start.p]->get_string()->length(); //old offset
	paragraphs[p_selection->start.p]->get_string()->replace_sstring(p_selection->start.o, p_selection->end.o, p_text);
	p_selection->end.o += (paragraphs[p_selection->start.p]->get_string()->length() - _len);

	p_selection->start = p_selection->end;
	p_selection->caret = p_selection->end;

	selection->disconnect("selection_changed", this, "_update_ctx_rect");
	selection = p_selection;
	selection->connect("selection_changed", this, "_update_ctx_rect");

	emit_signal("cursor_changed");
	update();
}

#ifdef GODOT_MODULE
void TLProtoControl::_gui_input(const Ref<InputEvent> &p_event) {
#else
void TLProtoControl::_gui_input(InputEvent *p_event) {
#endif

	if (!selectable)
		return;

#ifdef GODOT_MODULE
	Ref<InputEventMouseButton> b = p_event;
	if (b.is_valid()) {
#else
	InputEventMouseButton *b = cast_to<InputEventMouseButton>(p_event);
	if (b) {
#endif
		//LClick -> cursor
		if (b->get_button_mask() & GLOBAL_CONST(BUTTON_MASK_LEFT)) {
			_hit_test(b->get_position(), b->get_shift());
			emit_signal("cursor_changed");
			accept_event();
			update();
		}
	}

#ifdef GODOT_MODULE
	Ref<InputEventMouseMotion> m = p_event;
	if (m.is_valid()) {
#else
	InputEventMouseMotion *m = cast_to<InputEventMouseMotion>(p_event);
	if (m) {
#endif
		//LDrag -> select
		if (m->get_button_mask() & GLOBAL_CONST(BUTTON_MASK_LEFT)) {
			_hit_test(m->get_position(), true);
			emit_signal("cursor_changed");
			accept_event();
			update();
		}
	}

#ifdef GODOT_MODULE
	Ref<InputEventKey> k = p_event;
	if (k.is_valid()) {
#else
	InputEventKey *k = cast_to<InputEventKey>(p_event);
	if (k) {
#endif
		if (k->is_pressed()) {
			unsigned int code = k->get_scancode();

			if (code == GLOBAL_CONST(KEY_LEFT)) {
				if (k->get_command()) {
					_change_selection(k->get_shift(), REV_WORD, last_inp_dir);
				} else {
					_change_selection(k->get_shift(), REV_CHAR, last_inp_dir);
				}
				emit_signal("cursor_changed");
				accept_event();
				update();
			} else if (code == GLOBAL_CONST(KEY_RIGHT)) {
				if (k->get_command()) {
					_change_selection(k->get_shift(), FWD_WORD, last_inp_dir);
				} else {
					_change_selection(k->get_shift(), FWD_CHAR, last_inp_dir);
				}
				emit_signal("cursor_changed");
				accept_event();
				update();
			} else if (code == GLOBAL_CONST(KEY_UP)) {
				if (k->get_command()) {
					_change_selection(k->get_shift(), PARA_START, last_inp_dir);
				} else {
					_change_selection(k->get_shift(), REV_LINE, last_inp_dir);
				}
				emit_signal("cursor_changed");
				accept_event();
				update();
			} else if (code == GLOBAL_CONST(KEY_DOWN)) {
				if (k->get_command()) {
					_change_selection(k->get_shift(), PARA_END, last_inp_dir);
				} else {
					_change_selection(k->get_shift(), FWD_LINE, last_inp_dir);
				}
				emit_signal("cursor_changed");
				accept_event();
				update();
			} else if (code == GLOBAL_CONST(KEY_HOME)) {
				if (k->get_command()) {
					_change_selection(k->get_shift(), TEXT_START, last_inp_dir);
				} else {
					_change_selection(k->get_shift(), LINE_START, last_inp_dir);
				}
				emit_signal("cursor_changed");
				accept_event();
				update();
			} else if (code == GLOBAL_CONST(KEY_END)) {
				if (k->get_command()) {
					_change_selection(k->get_shift(), TEXT_END, last_inp_dir);
				} else {
					_change_selection(k->get_shift(), LINE_END, last_inp_dir);
				}
				emit_signal("cursor_changed");
				accept_event();
				update();
			} else if (code == GLOBAL_CONST(KEY_V)) {
				if (!readonly) {
					if (k->get_command() && !k->get_shift() && !k->get_alt()) {
						//plain text paste
						String clipboard = OS::get_singleton()->get_clipboard();
						replace_text(selection, clipboard);
						accept_event();
						emit_signal("cursor_changed");
						_update_ctx_rect();
					}
				}
			} else if (code == GLOBAL_CONST(KEY_C)) {
				if (!readonly) {
					if (k->get_command() && !k->get_shift() && !k->get_alt()) {
						//plain text copy
						String text;
						for (int i = selection->start.p; i <= selection->end.p; i++) {
							if (i == selection->start.p) {
								text += paragraphs[i]->get_string()->substr(selection->start.o, paragraphs[i]->get_string()->length(), false)->get_text();
							} else if (i == selection->end.p) {
								text += paragraphs[i]->get_string()->substr(0, selection->end.o, false)->get_text();
							} else {
								text += paragraphs[i]->get_string()->get_text();
							}
							text += "\n\n";
						}
						OS::get_singleton()->set_clipboard(text);
					}
				}
			} else if (code == GLOBAL_CONST(KEY_X)) {
				if (!readonly) {
					if (k->get_command() && !k->get_shift() && !k->get_alt()) {
						//plain text cut
						String text;
						for (int i = selection->start.p; i <= selection->end.p; i++) {
							if (i == selection->start.p) {
								text += paragraphs[i]->get_string()->substr(selection->start.o, paragraphs[i]->get_string()->length(), false)->get_text();
							} else if (i == selection->end.p) {
								text += paragraphs[i]->get_string()->substr(0, selection->end.o, false)->get_text();
							} else {
								text += paragraphs[i]->get_string()->get_text();
							}
							text += "\n\n";
						}
						OS::get_singleton()->set_clipboard(text);

						replace_text(selection, "");
						accept_event();
						emit_signal("cursor_changed");
						_update_ctx_rect();
					}
				}
			} else if (code == GLOBAL_CONST(KEY_ENTER)) {
				if (!readonly) {
					if (k->get_shift()) {
						replace_text(selection, "\n");
					} else {
						Ref<TLShapedParagraph> _first;
#ifdef GODOT_MODULE
						_first.instance();
#else
						_first = Ref<TLShapedParagraph>::__internal_constructor(TLShapedParagraph::_new());
#endif
						_first->connect("paragraph_changed", this, "_update_ctx_rect");
						_first->copy_properties(paragraphs[selection->start.p]);
						_first->set_string(paragraphs[selection->start.p]->get_string()->substr(0, selection->start.o, TEXT_TRIM_BREAK));

						Ref<TLShapedParagraph> _second;
#ifdef GODOT_MODULE
						_second.instance();
#else
						_second = Ref<TLShapedParagraph>::__internal_constructor(TLShapedParagraph::_new());
#endif
						_second->connect("paragraph_changed", this, "_update_ctx_rect");
						_second->copy_properties(paragraphs[selection->end.p]);
						_second->set_string(paragraphs[selection->end.p]->get_string()->substr(selection->end.o, paragraphs[selection->end.p]->get_string()->length(), TEXT_TRIM_BREAK));

						for (int i = selection->start.p; i <= selection->end.p; i++) {
							paragraphs[selection->start.p]->disconnect("paragraph_changed", this, "_update_ctx_rect");
							paragraphs.erase(paragraphs.begin() + selection->start.p);
						}
						paragraphs.insert(paragraphs.begin() + selection->start.p, _second);
						paragraphs.insert(paragraphs.begin() + selection->start.p, _first);

						selection->start.p++;
						selection->start.o = 0;
						selection->end = selection->start;
						selection->caret = selection->start;

						accept_event();
						emit_signal("cursor_changed");
						_update_ctx_rect();
					}
				}
			} else if (code == GLOBAL_CONST(KEY_BACKSPACE)) {
				if (!readonly) {
					if ((selection->start.p == selection->end.p) && (selection->start.o == selection->end.o)) {
						_change_selection(true, REV_CHAR, last_inp_dir);
					}
					replace_text(selection, "");
					accept_event();
					emit_signal("cursor_changed");
					_update_ctx_rect();
				}
			} else if (code == GLOBAL_CONST(KEY_DELETE)) {
				if (!readonly) {
					if ((selection->start.p == selection->end.p) && (selection->start.o == selection->end.o)) {
						_change_selection(true, FWD_CHAR, last_inp_dir);
					}
					replace_text(selection, "");
					accept_event();
					emit_signal("cursor_changed");
					_update_ctx_rect();
				}
			}

			if (!k->get_alt() && !k->get_command() && !k->get_metakey()) {
				if (!readonly) {
					if (k->get_unicode() >= 32 && k->get_scancode() != GLOBAL_CONST(KEY_DELETE)) {
#ifdef GODOT_MODULE
						CharType ucodestr[2] = { (CharType)k->get_unicode(), 0 };
						replace_text(selection, ucodestr);
#else
						replace_text(selection, (wchar_t)k->get_unicode());
#endif
						last_inp_dir = paragraphs[selection->caret.p]->get_string()->get_char_direction(paragraphs[selection->caret.p]->get_string()->prev_safe_bound(selection->caret.o));
						emit_signal("cursor_changed");
						accept_event();
						_update_ctx_rect();
					}
				}
			}
		}
	}
}

void TLProtoControl::debug_draw(RID p_canvas_item, const Point2 p_position, const Point2 p_hit_position, bool p_draw_brk_ops, bool p_draw_jst_ops) {

	float y_ofs = margin[MARGIN_TOP];
	if (p_hit_position.y < margin[MARGIN_TOP]) {
		return;
	}
	for (int i = 0; i < paragraphs.size(); i++) {
		if (paragraphs[i]->get_lines() > 0) {
			std::vector<int> bounds = paragraphs[i]->get_line_bounds();
			for (int j = 0; j < paragraphs[i]->get_lines(); j++) {
				if (paragraphs[i]->get_line(j).is_valid()) {
					if (p_hit_position.y >= y_ofs && p_hit_position.y < y_ofs + paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing()) {
						paragraphs[i]->get_line(j)->draw_dbg(p_canvas_item, p_position, Color(0, 0, 0), p_draw_brk_ops, p_draw_jst_ops);
						return;
					}
					y_ofs += paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing();
				}
			}
		}
		y_ofs += para_spacing;
	}
}

void TLProtoControl::debug_draw_as_hex(RID p_canvas_item, const Point2 p_position, const Point2 p_hit_position, bool p_draw_brk_ops, bool p_draw_jst_ops) {

	float y_ofs = margin[MARGIN_TOP];
	if (p_hit_position.y < margin[MARGIN_TOP]) {
		return;
	}
	for (int i = 0; i < paragraphs.size(); i++) {
		if (paragraphs[i]->get_lines() > 0) {
			std::vector<int> bounds = paragraphs[i]->get_line_bounds();
			for (int j = 0; j < paragraphs[i]->get_lines(); j++) {
				if (paragraphs[i]->get_line(j).is_valid()) {
					if (p_hit_position.y >= y_ofs && p_hit_position.y < y_ofs + paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing()) {
						paragraphs[i]->get_line(j)->draw_as_hex(p_canvas_item, p_position, Color(0, 0, 0), p_draw_brk_ops, p_draw_jst_ops);
						return;
					}
					y_ofs += paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing();
				}
			}
		}
		y_ofs += para_spacing;
	}
}

void TLProtoControl::debug_draw_logical_as_hex(RID p_canvas_item, const Point2 p_position, const Point2 p_hit_position, bool p_draw_brk_ops, bool p_draw_jst_ops) {

	float y_ofs = margin[MARGIN_TOP];
	if (p_hit_position.y < margin[MARGIN_TOP]) {
		return;
	}
	for (int i = 0; i < paragraphs.size(); i++) {
		if (paragraphs[i]->get_lines() > 0) {
			std::vector<int> bounds = paragraphs[i]->get_line_bounds();
			for (int j = 0; j < paragraphs[i]->get_lines(); j++) {
				if (paragraphs[i]->get_line(j).is_valid()) {
					if (p_hit_position.y >= y_ofs && p_hit_position.y < y_ofs + paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing()) {
						paragraphs[i]->get_line(j)->draw_logical_as_hex(p_canvas_item, p_position, Color(0, 0, 0), p_draw_brk_ops, p_draw_jst_ops);
						return;
					}
					y_ofs += paragraphs[i]->get_line(j)->get_height() * paragraphs[i]->get_line_spacing();
				}
			}
		}
		y_ofs += para_spacing;
	}
}

float TLProtoControl::_draw_paragraph(Ref<TLShapedParagraph> p_para, int p_index, float p_offset) {

	Size2 size = get_size();
	RID ci = get_canvas_item();
	Size2 psize = p_para->get_size();

	//draw current paragraph background
	VisualServer::get_singleton()->canvas_item_add_rect(ci, Rect2(Point2(margin[MARGIN_LEFT], p_offset), Size2(psize.x + p_para->get_indent(), psize.y)), p_para->get_back_color());

	if (p_para->get_lines() == 0) {
		//empty paragraph
		float x_ofs = margin[MARGIN_LEFT];
		if (p_para->get_width() > 0) {
			if (p_para->get_halign() == PARA_HALIGN_RIGHT) {
				x_ofs = p_para->get_width();
			} else if (p_para->get_halign() == PARA_HALIGN_CENTER) {
				x_ofs = (p_para->get_width() / 2);
			}
		}
		if (in_focus && selectable) {
			if (selection->caret.p == p_index) {
				Point2 n_caret_pos = Point2(p_para->get_indent() + x_ofs, p_offset);
				if (n_caret_pos != caret_pos) {
					caret_pos = n_caret_pos;
					emit_signal("cursor_changed");
				}
				VisualServer::get_singleton()->canvas_item_add_rect(ci, Rect2(caret_pos, Size2(1, p_para->get_string()->get_height() + p_para->get_line_spacing())), cursor_color);
			}
		}
		p_offset += p_para->get_string()->get_height() * p_para->get_line_spacing();
	} else {
		int prev = 0;
		std::vector<int> bounds = p_para->get_line_bounds();
		for (int j = 0; j < p_para->get_lines(); j++) {
			float x_ofs = margin[MARGIN_LEFT];
			if (p_para->get_width() > 0) {
				if (p_para->get_halign() == PARA_HALIGN_RIGHT) {
					x_ofs = (p_para->get_width() - p_para->get_line(j)->get_width());
				} else if (p_para->get_halign() == PARA_HALIGN_CENTER) {
					x_ofs = ((p_para->get_width() - p_para->get_line(j)->get_width()) / 2);
				}
			}

			if (p_para->get_line(j).is_valid()) {
				p_offset += p_para->get_line(j)->get_ascent();
				if ((p_offset <= size.height) && (p_offset + p_para->get_line(j)->get_descent() > 0.0f)) {
					//draw selection
					if (selectable) {
						if (p_index == -1) {
							if (in_focus) {
								int _start = -1;
								int _end = -1;

								//IME border
								if (selection->start.o >= prev && selection->start.o <= bounds[j]) {
									_start = selection->start.o - prev;
								} else if (selection->start.o > bounds[j]) {
									_start = bounds[j] - prev;
								} else if (selection->start.o < prev) {
									_start = 0;
								}
								if (selection->start.o + ime_len >= prev && selection->start.o + ime_len <= bounds[j]) {
									_end = selection->start.o + ime_len - prev;
								} else if (selection->start.o + ime_len > bounds[j]) {
									_end = bounds[j] - prev;
								} else if (selection->start.o + ime_len < prev) {
									_end = 0;
								}
								if (_start != _end && _start != -1 && _end != -1) {
									std::vector<Rect2> rects = p_para->get_line(j)->get_highlight_shapes(_start, _end);
									for (int k = 0; k < rects.size(); k++) {
										VisualServer::get_singleton()->canvas_item_add_rect(ci, Rect2(Point2(p_para->get_indent() + x_ofs, p_offset - p_para->get_line(j)->get_ascent()) + rects[k].position, rects[k].size), ime_selection_color);
									}
								}

								//IME selection
								if (selection->start.o + ime_cursor >= prev && selection->start.o + ime_cursor <= bounds[j]) {
									_start = selection->start.o + ime_cursor - prev;
								} else if (selection->start.o + ime_cursor > bounds[j]) {
									_start = bounds[j] - prev;
								} else if (selection->start.o + ime_cursor < prev) {
									_start = 0;
								}
								if (selection->start.o + ime_cursor + ime_selection_len >= prev && selection->start.o + ime_cursor + ime_selection_len <= bounds[j]) {
									_end = selection->start.o + ime_cursor + ime_selection_len - prev;
								} else if (selection->start.o + ime_cursor + ime_selection_len > bounds[j]) {
									_end = bounds[j] - prev;
								} else if (selection->start.o + ime_cursor + ime_selection_len < prev) {
									_end = 0;
								}
								if (_start != _end && _start != -1 && _end != -1) {
									std::vector<Rect2> rects = p_para->get_line(j)->get_highlight_shapes(_start, _end);
									for (int k = 0; k < rects.size(); k++) {
										Rect2 _rect = Rect2(Point2(p_para->get_indent() + x_ofs, p_offset - p_para->get_line(j)->get_ascent()) + rects[k].position, rects[k].size);
										Point2 n_caret_pos = _rect.position + Point2(0, _rect.size.height);
										if (n_caret_pos != caret_pos) {
											caret_pos = n_caret_pos;
											emit_signal("cursor_changed");
										}
										VisualServer::get_singleton()->canvas_item_add_rect(ci, Rect2(caret_pos, Size2(_rect.size.width, 2)), cursor_color);
									}
								}
							}
						} else if (selection->end != selection->start) {
							//Normal selection
							int _start = -1;
							int _end = -1;
							if (selection->start.p == p_index) {
								if (selection->start.o >= prev && selection->start.o <= bounds[j]) {
									_start = selection->start.o - prev;
								} else if (selection->start.o > bounds[j]) {
									_start = bounds[j] - prev;
								} else if (selection->start.o < prev) {
									_start = 0;
								}
							} else if (selection->start.p > p_index) {
								_start = bounds[j] - prev;
							} else if (selection->start.p < p_index) {
								_start = 0;
							}
							if (selection->end.p == p_index) {
								if (selection->end.o >= prev && selection->end.o <= bounds[j]) {
									_end = selection->end.o - prev;
								} else if (selection->end.o > bounds[j]) {
									_end = bounds[j] - prev;
								} else if (selection->end.o < prev) {
									_end = 0;
								}
							} else if (selection->end.p > p_index) {
								_end = bounds[j] - prev;
							} else if (selection->end.p < p_index) {
								_end = 0;
							}
							if (_start != _end && _start != -1 && _end != -1) {
								std::vector<Rect2> rects = p_para->get_line(j)->get_highlight_shapes(MIN(_start, _end), MAX(_start, _end));
								for (int k = 0; k < rects.size(); k++) {
									VisualServer::get_singleton()->canvas_item_add_rect(ci, Rect2(Point2(p_para->get_indent() + x_ofs, p_offset - p_para->get_line(j)->get_ascent()) + rects[k].position, rects[k].size), selection_color);
								}
							}
						}
					}

					//draw content
					p_para->get_line(j)->draw(ci, Point2(p_para->get_indent() + x_ofs, p_offset), Color(0, 0, 0));

					//draw cursor
					if (in_focus && selectable) {
						if (selection->caret.p == p_index) {
							if ((selection->caret.o >= prev && selection->caret.o < bounds[j]) || ((j == bounds.size() - 1) && (selection->caret.o == bounds[j]))) {
								if (p_para->get_line(j)->length() > 0) {
									std::vector<float> cur_ofs = p_para->get_line(j)->get_cursor_positions(selection->caret.o - prev, last_inp_dir);
									for (int k = 0; k < cur_ofs.size(); k++) {
										Point2 n_caret_pos = Point2(p_para->get_indent() + x_ofs + cur_ofs[k], p_offset - p_para->get_line(j)->get_ascent());
										if (n_caret_pos != caret_pos) {
											caret_pos = n_caret_pos;
											emit_signal("cursor_changed");
										}

										VisualServer::get_singleton()->canvas_item_add_rect(ci, Rect2(caret_pos, Size2(2, p_para->get_line(j)->get_height() + p_para->get_line_spacing())), cursor_color);
									}
								} else {
									Point2 n_caret_pos = Point2(p_para->get_indent() + x_ofs, p_offset - p_para->get_line(j)->get_ascent());
									if (n_caret_pos != caret_pos) {
										caret_pos = n_caret_pos;
										emit_signal("cursor_changed");
									}
									VisualServer::get_singleton()->canvas_item_add_rect(ci, Rect2(caret_pos, Size2(1, p_para->get_line(j)->get_height() + p_para->get_line_spacing())), cursor_color);
								}
							}
						}
					}
				}
				p_offset += p_para->get_line(j)->get_descent() * p_para->get_line_spacing();
				prev = bounds[j];
			}
		}
	}
	return p_offset;
}

void TLProtoControl::_notification(int p_what) {

	switch (p_what) {
		case NOTIFICATION_DRAW: {
			RID ci = get_canvas_item();
			VisualServer::get_singleton()->canvas_item_set_clip(get_canvas_item(), true);

			VisualServer::get_singleton()->canvas_item_add_rect(ci, Rect2(Point2(margin[MARGIN_LEFT], margin[MARGIN_TOP]), content_size), bg_color);

			//real draw
			float y_ofs = margin[MARGIN_TOP];
			for (int i = 0; i < paragraphs.size(); i++) {
				if (ime_temp_para.is_valid()) {
					//skip paragraphs in selection range
					if (i == selection->start.p) {
						//draw ime
						y_ofs = _draw_paragraph(ime_temp_para, -1, y_ofs) + para_spacing;
						continue;
					} else if ((i > selection->start.p) && (i <= selection->end.p)) {
						continue;
					}
				}
				y_ofs = _draw_paragraph(paragraphs[i], i, y_ofs) + para_spacing;
			}
		} break;
		case NOTIFICATION_FOCUS_ENTER: {

			if (!readonly && selectable) {
				OS::get_singleton()->set_ime_active(true);
				float y_ofs = margin[MARGIN_TOP];
				for (int i = 0; i <= selection->start.p; i++) {
					y_ofs = y_ofs + paragraphs[i]->get_size().y + para_spacing;
				}
				OS::get_singleton()->set_ime_position(get_global_position() + Point2(0, y_ofs)); // TODO + cursor_pos.x
			}

			in_focus = true;
			update();
		} break;
		case NOTIFICATION_FOCUS_EXIT: {

			OS::get_singleton()->set_ime_position(Point2());
			OS::get_singleton()->set_ime_active(false);

			//0. free existing ime paragraph
			if (ime_temp_para.is_valid()) {
				ime_temp_para->disconnect("paragraph_changed", this, "_update_ctx_rect");
				ime_temp_para = Ref<TLShapedParagraph>();
			}

			in_focus = false;
			update();
		} break;
		case MainLoop::NOTIFICATION_OS_IME_UPDATE: {

			if (in_focus && !readonly && selectable) {

				//0. free existing ime paragraph
				if (ime_temp_para.is_valid()) {
					ime_temp_para->disconnect("paragraph_changed", this, "_update_ctx_rect");
					ime_temp_para = Ref<TLShapedParagraph>();
				}

				//1. construct ime paragraph
				String ime_text = OS::get_singleton()->get_ime_text();
				if (ime_text != "") {
					ime_cursor = OS::get_singleton()->get_ime_selection().x;
					ime_selection_len = OS::get_singleton()->get_ime_selection().y;

#ifdef GODOT_MODULE
					ime_temp_para.instance();
#else
					ime_temp_para = Ref<TLShapedParagraph>::__internal_constructor(TLShapedParagraph::_new());
#endif
					ime_temp_para->connect("paragraph_changed", this, "_update_ctx_rect");
					ime_temp_para->copy_properties(paragraphs[selection->start.p]);
					ime_temp_para->get_string()->add_sstring(paragraphs[selection->start.p]->get_string());

					int offset = 0;
					if (selection->start.p != selection->end.p) {
						int first_para = selection->start.p;
						int last_para = selection->end.p;

						//merge paragraphs
						offset = paragraphs[first_para]->get_string()->length();
						for (int i = first_para + 1; i <= last_para; i++) {
							ime_temp_para->get_string()->add_sstring(paragraphs[i]->get_string());
							if (i != last_para) offset += paragraphs[i]->get_string()->length();
						}
					}

					int _len = ime_temp_para->get_string()->length() - (selection->end.o + offset - selection->start.o);
					ime_temp_para->get_string()->replace_text(selection->start.o, selection->end.o + offset, ime_text);

					ime_len = ime_temp_para->get_string()->length() - _len;

					//2. update ime input position
					float y_ofs = margin[MARGIN_TOP];
					for (int i = 0; i <= selection->start.p; i++) {
						y_ofs = y_ofs + paragraphs[i]->get_size().y + para_spacing;
					}
					OS::get_singleton()->set_ime_position(get_global_position() + Point2(0, y_ofs)); // TODO  + cursor_pos.x
				}
				update();
			}
		} break;
	}
}

void TLProtoControl::set_back_color(Color p_color) {

	bg_color = p_color;
	update();
}

Color TLProtoControl::get_back_color() const {

	return bg_color;
}

void TLProtoControl::set_paragraph_spacing(float p_value) {

	para_spacing = p_value;
	update();
}

float TLProtoControl::get_paragraph_spacing() const {

	return para_spacing;
}

void TLProtoControl::set_readonly(bool p_value) {

	readonly = p_value;
	update();
}

bool TLProtoControl::get_readonly() const {

	return readonly;
}

void TLProtoControl::set_selectable(bool p_value) {

	selectable = p_value;
	update();
}

bool TLProtoControl::get_selectable() const {

	return selectable;
}

#ifdef GODOT_MODULE

void TLProtoControl::_bind_methods() {

	ClassDB::bind_method(D_METHOD("clear"), &TLProtoControl::clear);
	ClassDB::bind_method(D_METHOD("_update_ctx_rect"), &TLProtoControl::_update_ctx_rect);

	ClassDB::bind_method(D_METHOD("set_back_color", "color"), &TLProtoControl::set_back_color);
	ClassDB::bind_method(D_METHOD("get_back_color"), &TLProtoControl::get_back_color);
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "back_color"), "set_back_color", "get_back_color");

	ClassDB::bind_method(D_METHOD("set_paragraph_spacing", "value"), &TLProtoControl::set_paragraph_spacing);
	ClassDB::bind_method(D_METHOD("get_paragraph_spacing"), &TLProtoControl::get_paragraph_spacing);
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "paragraph_spacing"), "set_paragraph_spacing", "get_paragraph_spacing");

	ClassDB::bind_method(D_METHOD("get_paragraphs"), &TLProtoControl::get_paragraphs);
	ClassDB::bind_method(D_METHOD("get_paragraph", "index"), &TLProtoControl::get_paragraph);
	ClassDB::bind_method(D_METHOD("set_paragraph", "para", "index"), &TLProtoControl::set_paragraph);

	ClassDB::bind_method(D_METHOD("insert_paragraph", "para", "index"), &TLProtoControl::insert_paragraph);
	ClassDB::bind_method(D_METHOD("remove_paragraph", "index"), &TLProtoControl::remove_paragraph);

	ClassDB::bind_method(D_METHOD("get_caret_position"), &TLProtoControl::get_caret_position);

	ClassDB::bind_method(D_METHOD("replace_text", "selection", "text"), &TLProtoControl::replace_text);
	ClassDB::bind_method(D_METHOD("replace_utf8", "selection", "text"), &TLProtoControl::replace_utf8);
	ClassDB::bind_method(D_METHOD("replace_utf16", "selection", "text"), &TLProtoControl::replace_utf16);
	ClassDB::bind_method(D_METHOD("replace_utf32", "selection", "text"), &TLProtoControl::replace_utf32);
	ClassDB::bind_method(D_METHOD("replace_sstring", "selection", "text"), &TLProtoControl::replace_sstring);

	ClassDB::bind_method(D_METHOD("add_attribute", "selection", "attribute", "value"), &TLProtoControl::add_attribute);
	ClassDB::bind_method(D_METHOD("remove_attribute", "selection", "attribute"), &TLProtoControl::remove_attribute);
	ClassDB::bind_method(D_METHOD("remove_attributes", "selection"), &TLProtoControl::remove_attributes);
	ClassDB::bind_method(D_METHOD("set_paragraph_width", "selection", "width"), &TLProtoControl::set_paragraph_width);
	ClassDB::bind_method(D_METHOD("set_paragraph_indent", "selection", "indent"), &TLProtoControl::set_paragraph_indent);
	ClassDB::bind_method(D_METHOD("set_paragraph_back_color", "selection", "bcolor"), &TLProtoControl::set_paragraph_back_color);
	ClassDB::bind_method(D_METHOD("set_paragraph_line_spacing", "selection", "line_spacing"), &TLProtoControl::set_paragraph_line_spacing);
	ClassDB::bind_method(D_METHOD("set_paragraph_brk_flags", "selection", "flags"), &TLProtoControl::set_paragraph_brk_flags);
	ClassDB::bind_method(D_METHOD("set_paragraph_jst_flags", "selection", "flags"), &TLProtoControl::set_paragraph_jst_flags);
	ClassDB::bind_method(D_METHOD("set_paragraph_halign", "selection", "halign"), &TLProtoControl::set_paragraph_halign);

	ClassDB::bind_method(D_METHOD("get_selection"), &TLProtoControl::get_selection);
	ClassDB::bind_method(D_METHOD("set_selection", "selection"), &TLProtoControl::set_selection);

	ClassDB::bind_method(D_METHOD("get_cluster_debug_info_hit_test", "position"), &TLProtoControl::get_cluster_debug_info_hit_test);
	ClassDB::bind_method(D_METHOD("get_cluster_glyphs_hit_test", "position"), &TLProtoControl::get_cluster_glyphs_hit_test);
	ClassDB::bind_method(D_METHOD("get_cluster_rect_hit_test", "position"), &TLProtoControl::get_cluster_rect_hit_test);

	ClassDB::bind_method(D_METHOD("get_readonly"), &TLProtoControl::get_readonly);
	ClassDB::bind_method(D_METHOD("set_readonly", "readonly"), &TLProtoControl::set_readonly);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "readonly"), "set_readonly", "get_readonly");

	ClassDB::bind_method(D_METHOD("get_selectable"), &TLProtoControl::get_selectable);
	ClassDB::bind_method(D_METHOD("set_selectable", "selectable"), &TLProtoControl::set_selectable);
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "selectable"), "set_selectable", "get_selectable");

	ClassDB::bind_method(D_METHOD("debug_draw", "rid", "position", "hit_position", "draw_brk_ops", "draw_jst_ops"), &TLProtoControl::debug_draw);
	ClassDB::bind_method(D_METHOD("debug_draw_as_hex", "rid", "position", "hit_position", "draw_brk_ops", "draw_jst_ops"), &TLProtoControl::debug_draw_as_hex);
	ClassDB::bind_method(D_METHOD("debug_draw_logical_as_hex", "rid", "position", "hit_position", "draw_brk_ops", "draw_jst_ops"), &TLProtoControl::debug_draw_logical_as_hex);

	ClassDB::bind_method(D_METHOD("_gui_input"), &TLProtoControl::_gui_input);

	ADD_SIGNAL(MethodInfo("cursor_changed"));
	ADD_SIGNAL(MethodInfo("paragraph_changed"));
}

#else

void TLProtoControl::_register_methods() {

	register_method("clear", &TLProtoControl::clear);
	register_method("_update_ctx_rect", &TLProtoControl::_update_ctx_rect);

	register_method("set_back_color", &TLProtoControl::set_back_color);
	register_method("get_back_color", &TLProtoControl::get_back_color);
	register_property<TLProtoControl, Color>("back_color", &TLProtoControl::set_back_color, &TLProtoControl::get_back_color, Color(1, 1, 1, 0.5));

	register_method("set_paragraph_spacing", &TLProtoControl::set_paragraph_spacing);
	register_method("get_paragraph_spacing", &TLProtoControl::get_paragraph_spacing);
	register_property<TLProtoControl, float>("paragraph_spacing", &TLProtoControl::set_paragraph_spacing, &TLProtoControl::get_paragraph_spacing, 3.0f);

	register_method("get_paragraphs", &TLProtoControl::get_paragraphs);
	register_method("get_paragraph", &TLProtoControl::get_paragraph);
	register_method("set_paragraph", &TLProtoControl::set_paragraph);

	register_method("insert_paragraph", &TLProtoControl::insert_paragraph);
	register_method("remove_paragraph", &TLProtoControl::remove_paragraph);

	register_method("get_caret_position", &TLProtoControl::get_caret_position);

	register_method("replace_text", &TLProtoControl::replace_text);
	register_method("replace_utf8", &TLProtoControl::replace_utf8);
	register_method("replace_utf16", &TLProtoControl::replace_utf16);
	register_method("replace_utf32", &TLProtoControl::replace_utf32);
	register_method("replace_sstring", &TLProtoControl::replace_sstring);

	register_method("add_attribute", &TLProtoControl::add_attribute);
	register_method("remove_attribute", &TLProtoControl::remove_attribute);
	register_method("remove_attributes", &TLProtoControl::remove_attributes);
	register_method("set_paragraph_width", &TLProtoControl::set_paragraph_width);
	register_method("set_paragraph_indent", &TLProtoControl::set_paragraph_indent);
	register_method("set_paragraph_back_color", &TLProtoControl::set_paragraph_back_color);
	register_method("set_paragraph_line_spacing", &TLProtoControl::set_paragraph_line_spacing);
	register_method("set_paragraph_brk_flags", &TLProtoControl::set_paragraph_brk_flags);
	register_method("set_paragraph_jst_flags", &TLProtoControl::set_paragraph_jst_flags);
	register_method("set_paragraph_halign", &TLProtoControl::set_paragraph_halign);

	register_method("get_selection", &TLProtoControl::get_selection);
	register_method("set_selection", &TLProtoControl::set_selection);

	register_method("get_readonly", &TLProtoControl::get_readonly);
	register_method("set_readonly", &TLProtoControl::set_readonly);
	register_property<TLProtoControl, bool>("readonly", &TLProtoControl::set_readonly, &TLProtoControl::get_readonly, false);

	register_method("get_selectable", &TLProtoControl::get_selectable);
	register_method("set_selectable", &TLProtoControl::set_selectable);
	register_property<TLProtoControl, bool>("selectable", &TLProtoControl::set_selectable, &TLProtoControl::get_selectable, false);

	register_method("get_cluster_debug_info_hit_test", &TLProtoControl::get_cluster_debug_info_hit_test);
	register_method("get_cluster_glyphs_hit_test", &TLProtoControl::get_cluster_glyphs_hit_test);
	register_method("get_cluster_rect_hit_test", &TLProtoControl::get_cluster_rect_hit_test);

	register_method("_gui_input", &TLProtoControl::_gui_input);
	register_method("get_minimum_size", &TLProtoControl::get_minimum_size);

	register_method("debug_draw", &TLProtoControl::debug_draw);
	register_method("debug_draw_as_hex", &TLProtoControl::debug_draw_as_hex);
	register_method("debug_draw_logical_as_hex", &TLProtoControl::debug_draw_logical_as_hex);

	register_method("_notification", &TLProtoControl::_notification);

	register_signal<TLProtoControl>("cursor_changed");
	register_signal<TLProtoControl>("paragraph_changed");
}

#endif
