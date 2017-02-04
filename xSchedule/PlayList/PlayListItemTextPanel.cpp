#include "PlayListItemTextPanel.h"
#include "PlayListItemText.h"

//(*InternalHeaders(PlayListItemTextPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/colordlg.h>
#include "../FSEQFile.h"
#include "../xScheduleMain.h"
#include "../ScheduleOptions.h"
#include "../ScheduleManager.h"
#include "../MatrixMapper.h"

//(*IdInit(PlayListItemTextPanel)
const long PlayListItemTextPanel::ID_STATICTEXT11 = wxNewId();
const long PlayListItemTextPanel::ID_CHOICE5 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT2 = wxNewId();
const long PlayListItemTextPanel::ID_CHOICE1 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT1 = wxNewId();
const long PlayListItemTextPanel::ID_TEXTCTRL1 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT3 = wxNewId();
const long PlayListItemTextPanel::ID_TEXTCTRL2 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT5 = wxNewId();
const long PlayListItemTextPanel::ID_FONTPICKERCTRL1 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT7 = wxNewId();
const long PlayListItemTextPanel::ID_CHOICE3 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT4 = wxNewId();
const long PlayListItemTextPanel::ID_CHOICE2 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT6 = wxNewId();
const long PlayListItemTextPanel::ID_SPINCTRL1 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT8 = wxNewId();
const long PlayListItemTextPanel::ID_BUTTON2 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT10 = wxNewId();
const long PlayListItemTextPanel::ID_CHOICE4 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT12 = wxNewId();
const long PlayListItemTextPanel::ID_SPINCTRL2 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT13 = wxNewId();
const long PlayListItemTextPanel::ID_SPINCTRL3 = wxNewId();
const long PlayListItemTextPanel::ID_STATICTEXT9 = wxNewId();
const long PlayListItemTextPanel::ID_TEXTCTRL3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PlayListItemTextPanel,wxPanel)
	//(*EventTable(PlayListItemTextPanel)
	//*)
END_EVENT_TABLE()

void PlayListItemTextPanel::SetChoiceFromString(wxChoice* choice, std::string value)
{
    choice->SetSelection(-1);
    for (size_t i = 0; i < choice->GetCount(); i++)
    {
        if (choice->GetString(i) == value)
        {
            choice->SetSelection(i);
            return;
        }
    }
}


PlayListItemTextPanel::PlayListItemTextPanel(wxWindow* parent, PlayListItemText* text,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    _text = text;

	//(*Initialize(PlayListItemTextPanel)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer1->AddGrowableCol(1);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Matrix:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer1->Add(StaticText11, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Choice_Matrices = new wxChoice(this, ID_CHOICE5, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
	FlexGridSizer1->Add(Choice_Matrices, 1, wxALL|wxEXPAND, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Type:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Choice_Type = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice_Type->SetSelection( Choice_Type->Append(_("Normal")) );
	Choice_Type->Append(_("Countdown"));
	FlexGridSizer1->Add(Choice_Type, 1, wxALL|wxEXPAND, 5);
	StaticText_Text = new wxStaticText(this, ID_STATICTEXT1, _("Text:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText_Text, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Text = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(TextCtrl_Text, 1, wxALL|wxEXPAND, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Format:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Format = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer1->Add(TextCtrl_Format, 1, wxALL|wxEXPAND, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Font:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FontPickerCtrl1 = new wxFontPickerCtrl(this, ID_FONTPICKERCTRL1, wxNullFont, wxDefaultPosition, wxDefaultSize, wxFNTP_FONTDESC_AS_LABEL|wxFNTP_USEFONT_FOR_LABEL, wxDefaultValidator, _T("ID_FONTPICKERCTRL1"));
	FlexGridSizer1->Add(FontPickerCtrl1, 1, wxALL|wxEXPAND, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Orientation:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Choice_Orientation = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	Choice_Orientation->SetSelection( Choice_Orientation->Append(_("Normal")) );
	Choice_Orientation->Append(_("Vertical Up"));
	Choice_Orientation->Append(_("Vertical Down"));
	Choice_Orientation->Append(_("Rotate Up 90"));
	Choice_Orientation->Append(_("Rotate Down 90"));
	FlexGridSizer1->Add(Choice_Orientation, 1, wxALL|wxEXPAND, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Movement:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Choice_Movement = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Choice_Movement->Append(_("None"));
	Choice_Movement->SetSelection( Choice_Movement->Append(_("Right to Left")) );
	Choice_Movement->Append(_("Left to Right"));
	Choice_Movement->Append(_("Bottom to Top"));
	Choice_Movement->Append(_("Top to Bottom"));
	FlexGridSizer1->Add(Choice_Movement, 1, wxALL|wxEXPAND, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Speed:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl_Speed = new wxSpinCtrl(this, ID_SPINCTRL1, _T("10"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 10, _T("ID_SPINCTRL1"));
	SpinCtrl_Speed->SetValue(_T("10"));
	FlexGridSizer1->Add(SpinCtrl_Speed, 1, wxALL|wxEXPAND, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Color:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer1->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Button_Color = new wxButton(this, ID_BUTTON2, _("Color"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer1->Add(Button_Color, 1, wxALL|wxEXPAND, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Blend Mode:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer1->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	Choice_BlendMode = new wxChoice(this, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	FlexGridSizer1->Add(Choice_BlendMode, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("X Position:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	FlexGridSizer1->Add(StaticText12, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl_X = new wxSpinCtrl(this, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxDefaultSize, 0, -1000, 1000, 0, _T("ID_SPINCTRL2"));
	SpinCtrl_X->SetValue(_T("0"));
	FlexGridSizer1->Add(SpinCtrl_X, 1, wxALL|wxEXPAND, 5);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Y Position:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	FlexGridSizer1->Add(StaticText13, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl_Y = new wxSpinCtrl(this, ID_SPINCTRL3, _T("0"), wxDefaultPosition, wxDefaultSize, 0, -1000, 1000, 0, _T("ID_SPINCTRL3"));
	SpinCtrl_Y->SetValue(_T("0"));
	FlexGridSizer1->Add(SpinCtrl_Y, 1, wxALL|wxEXPAND, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Duration:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer1->Add(StaticText9, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl_Duration = new wxTextCtrl(this, ID_TEXTCTRL3, _("0.050"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer1->Add(TextCtrl_Duration, 1, wxALL|wxEXPAND, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PlayListItemTextPanel::OnChoice_TypeSelect);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&PlayListItemTextPanel::OnButton_ColorClick);
	//*)

    auto bms = FSEQFile::GetBlendModes();
    for (auto it = bms.begin(); it != bms.end(); ++it)
    {
        Choice_BlendMode->AppendString(*it);
    }
    Choice_BlendMode->SetSelection(0);

    auto m = xScheduleFrame::GetScheduleManager()->GetOptions()->GetMatrices();
    for (auto it = m->begin(); it != m->end(); ++it)
    {
        Choice_Matrices->AppendString((*it)->GetName());
    }
    if (Choice_Matrices->GetCount() > 0) Choice_Matrices->SetSelection(0);

    TextCtrl_Text->SetValue(text->GetText());
    TextCtrl_Format->SetValue(text->GetFormat());
    SpinCtrl_Speed->SetValue(text->GetSpeed());
    FontPickerCtrl1->SetSelectedFont(text->GetFont());
    Button_Color->SetBackgroundColour(text->GetColour());
    SetChoiceFromString(Choice_Orientation, text->GetOrientation());
    SetChoiceFromString(Choice_Movement, text->GetMovement());
    SetChoiceFromString(Choice_Type, text->GetType());
    TextCtrl_Duration->SetValue(wxString::Format(wxT("%.3f"), (float)text->GetDuration() / 1000.0));
    Choice_BlendMode->SetSelection(text->GetBlendMode());
    SetChoiceFromString(Choice_Matrices, text->GetMatrix());
    SpinCtrl_X->SetValue(_text->GetX());
    SpinCtrl_Y->SetValue(_text->GetY());

    ValidateWindow();
}

PlayListItemTextPanel::~PlayListItemTextPanel()
{
	//(*Destroy(PlayListItemTextPanel)
	//*)

    _text->SetText(TextCtrl_Text->GetValue().ToStdString());
    _text->SetFormat(TextCtrl_Format->GetValue().ToStdString());
    _text->SetSpeed(SpinCtrl_Speed->GetValue());
    _text->SetFont(FontPickerCtrl1->GetSelectedFont());
    _text->SetColour(Button_Color->GetBackgroundColour());
    _text->SetOrientation(Choice_Orientation->GetStringSelection().ToStdString());
    _text->SetMovement(Choice_Movement->GetStringSelection().ToStdString());
    _text->SetType(Choice_Type->GetStringSelection().ToStdString());
    _text->SetDuration(wxAtof(TextCtrl_Duration->GetValue()) * 1000);
    _text->SetBlendMode((APPLYMETHOD)Choice_BlendMode->GetSelection());
    _text->SetMatrix(Choice_Matrices->GetStringSelection().ToStdString());
    _text->SetX(SpinCtrl_X->GetValue());
    _text->SetY(SpinCtrl_Y->GetValue());
}

void PlayListItemTextPanel::OnChoice_TypeSelect(wxCommandEvent& event)
{
    ValidateWindow();
}

void PlayListItemTextPanel::OnButton_ColorClick(wxCommandEvent& event)
{
    wxColourData colorData;
    wxColour colour = Button_Color->GetBackgroundColour();
    colorData.SetColour(colour);
    wxColourDialog dialog(this, &colorData);
    if (dialog.ShowModal() == wxID_OK)
    {
        wxColourData retData = dialog.GetColourData();
        colour = retData.GetColour();
        Button_Color->SetBackgroundColour(colour);
    }
}

void PlayListItemTextPanel::ValidateWindow()
{
    if (Choice_Type->GetStringSelection() == "Normal")
    {
        StaticText_Text->SetLabel("Text");
    }
    else
    {
        StaticText_Text->SetLabel("To Date/Time");
    }
}