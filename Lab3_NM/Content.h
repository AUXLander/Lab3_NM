#pragma once

namespace Lab3NM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Content
	/// </summary>
	public ref class Content : public System::Windows::Forms::Form
	{
	public:
		Content(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Content()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ pageNav;
	private: System::Windows::Forms::TabPage^ pageNav_p1;
	private: System::Windows::Forms::TabPage^ pageNav_p2;
	private: System::Windows::Forms::MenuStrip^ topMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ topMenu_i1;


	private: System::Windows::Forms::ToolStripMenuItem^ открытьЗадачуToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ topMenu_i2;
	private: System::Windows::Forms::GroupBox^ TaskGroupBox;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::PictureBox^ pictureTask;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ GraphChart;
	private: System::Windows::Forms::GroupBox^ SolveListGroupBox;
	private: System::Windows::Forms::Button^ SolveEditBtn;
	private: System::Windows::Forms::Button^ SolveDelBtn;
	private: System::Windows::Forms::Button^ SolveAddBtn;

	private: System::Windows::Forms::GroupBox^ SettingsGroupBox;
	private: System::Windows::Forms::Button^ SolveBtn;
	private: System::Windows::Forms::DataGridView^ dataGridView1;




	private: System::Windows::Forms::DataGridView^ SolveGrid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ const_var_x;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ const_var_u;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col0;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ col6;



















	protected:

	protected:



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Content::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->pageNav = (gcnew System::Windows::Forms::TabControl());
			this->pageNav_p1 = (gcnew System::Windows::Forms::TabPage());
			this->pageNav_p2 = (gcnew System::Windows::Forms::TabPage());
			this->topMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->topMenu_i1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьЗадачуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->topMenu_i2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TaskGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->pictureTask = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->GraphChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->SolveListGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->SolveAddBtn = (gcnew System::Windows::Forms::Button());
			this->SolveDelBtn = (gcnew System::Windows::Forms::Button());
			this->SolveEditBtn = (gcnew System::Windows::Forms::Button());
			this->SettingsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->SolveBtn = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->SolveGrid = (gcnew System::Windows::Forms::DataGridView());
			this->const_var_x = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->const_var_u = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col0 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->col6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pageNav->SuspendLayout();
			this->pageNav_p1->SuspendLayout();
			this->pageNav_p2->SuspendLayout();
			this->topMenu->SuspendLayout();
			this->TaskGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureTask))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GraphChart))->BeginInit();
			this->SolveListGroupBox->SuspendLayout();
			this->SettingsGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SolveGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// pageNav
			// 
			this->pageNav->Controls->Add(this->pageNav_p1);
			this->pageNav->Controls->Add(this->pageNav_p2);
			this->pageNav->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pageNav->Location = System::Drawing::Point(0, 24);
			this->pageNav->Name = L"pageNav";
			this->pageNav->SelectedIndex = 0;
			this->pageNav->Size = System::Drawing::Size(880, 436);
			this->pageNav->SizeMode = System::Windows::Forms::TabSizeMode::FillToRight;
			this->pageNav->TabIndex = 0;
			// 
			// pageNav_p1
			// 
			this->pageNav_p1->AutoScroll = true;
			this->pageNav_p1->Controls->Add(this->TaskGroupBox);
			this->pageNav_p1->ImeMode = System::Windows::Forms::ImeMode::On;
			this->pageNav_p1->Location = System::Drawing::Point(4, 22);
			this->pageNav_p1->Margin = System::Windows::Forms::Padding(10);
			this->pageNav_p1->Name = L"pageNav_p1";
			this->pageNav_p1->Padding = System::Windows::Forms::Padding(3);
			this->pageNav_p1->Size = System::Drawing::Size(872, 410);
			this->pageNav_p1->TabIndex = 0;
			this->pageNav_p1->Text = L"Панель управления";
			this->pageNav_p1->UseVisualStyleBackColor = true;
			// 
			// pageNav_p2
			// 
			this->pageNav_p2->Controls->Add(this->dataGridView1);
			this->pageNav_p2->Location = System::Drawing::Point(4, 22);
			this->pageNav_p2->Name = L"pageNav_p2";
			this->pageNav_p2->Padding = System::Windows::Forms::Padding(3);
			this->pageNav_p2->Size = System::Drawing::Size(872, 410);
			this->pageNav_p2->TabIndex = 1;
			this->pageNav_p2->Text = L"Таблица";
			this->pageNav_p2->UseVisualStyleBackColor = true;
			// 
			// topMenu
			// 
			this->topMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->topMenu_i1, this->topMenu_i2 });
			this->topMenu->Location = System::Drawing::Point(0, 0);
			this->topMenu->Name = L"topMenu";
			this->topMenu->Size = System::Drawing::Size(880, 24);
			this->topMenu->TabIndex = 1;
			this->topMenu->Text = L"menuStrip1";
			// 
			// topMenu_i1
			// 
			this->topMenu_i1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->открытьЗадачуToolStripMenuItem });
			this->topMenu_i1->Name = L"topMenu_i1";
			this->topMenu_i1->Size = System::Drawing::Size(48, 20);
			this->topMenu_i1->Text = L"Файл";
			// 
			// открытьЗадачуToolStripMenuItem
			// 
			this->открытьЗадачуToolStripMenuItem->Name = L"открытьЗадачуToolStripMenuItem";
			this->открытьЗадачуToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->открытьЗадачуToolStripMenuItem->Text = L"Открыть задачу";
			// 
			// topMenu_i2
			// 
			this->topMenu_i2->Name = L"topMenu_i2";
			this->topMenu_i2->Size = System::Drawing::Size(65, 20);
			this->topMenu_i2->Text = L"Справка";
			// 
			// TaskGroupBox
			// 
			this->TaskGroupBox->AutoSize = true;
			this->TaskGroupBox->Controls->Add(this->SettingsGroupBox);
			this->TaskGroupBox->Controls->Add(this->SolveListGroupBox);
			this->TaskGroupBox->Controls->Add(this->groupBox1);
			this->TaskGroupBox->Controls->Add(this->pictureTask);
			this->TaskGroupBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TaskGroupBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->TaskGroupBox->Location = System::Drawing::Point(3, 3);
			this->TaskGroupBox->Name = L"TaskGroupBox";
			this->TaskGroupBox->Size = System::Drawing::Size(866, 404);
			this->TaskGroupBox->TabIndex = 0;
			this->TaskGroupBox->TabStop = false;
			this->TaskGroupBox->Text = L"Название задачи";
			// 
			// pictureTask
			// 
			this->pictureTask->BackColor = System::Drawing::Color::Maroon;
			this->pictureTask->Location = System::Drawing::Point(6, 19);
			this->pictureTask->Name = L"pictureTask";
			this->pictureTask->Size = System::Drawing::Size(171, 90);
			this->pictureTask->TabIndex = 0;
			this->pictureTask->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->GraphChart);
			this->groupBox1->Location = System::Drawing::Point(483, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(377, 385);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"График";
			// 
			// GraphChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->GraphChart->ChartAreas->Add(chartArea1);
			this->GraphChart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend1->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Row;
			legend1->Name = L"Legend1";
			this->GraphChart->Legends->Add(legend1);
			this->GraphChart->Location = System::Drawing::Point(3, 16);
			this->GraphChart->Name = L"GraphChart";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->GraphChart->Series->Add(series1);
			this->GraphChart->Size = System::Drawing::Size(371, 366);
			this->GraphChart->TabIndex = 0;
			// 
			// SolveListGroupBox
			// 
			this->SolveListGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->SolveListGroupBox->Controls->Add(this->SolveGrid);
			this->SolveListGroupBox->Controls->Add(this->SolveEditBtn);
			this->SolveListGroupBox->Controls->Add(this->SolveDelBtn);
			this->SolveListGroupBox->Controls->Add(this->SolveAddBtn);
			this->SolveListGroupBox->Location = System::Drawing::Point(6, 115);
			this->SolveListGroupBox->Name = L"SolveListGroupBox";
			this->SolveListGroupBox->Size = System::Drawing::Size(114, 280);
			this->SolveListGroupBox->TabIndex = 2;
			this->SolveListGroupBox->TabStop = false;
			this->SolveListGroupBox->Text = L"Таблица Н.У.";
			// 
			// SolveAddBtn
			// 
			this->SolveAddBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SolveAddBtn->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->SolveAddBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SolveAddBtn.Image")));
			this->SolveAddBtn->Location = System::Drawing::Point(6, 244);
			this->SolveAddBtn->Name = L"SolveAddBtn";
			this->SolveAddBtn->Size = System::Drawing::Size(30, 30);
			this->SolveAddBtn->TabIndex = 0;
			this->SolveAddBtn->UseVisualStyleBackColor = true;
			// 
			// SolveDelBtn
			// 
			this->SolveDelBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SolveDelBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SolveDelBtn.Image")));
			this->SolveDelBtn->Location = System::Drawing::Point(78, 244);
			this->SolveDelBtn->Name = L"SolveDelBtn";
			this->SolveDelBtn->Size = System::Drawing::Size(30, 30);
			this->SolveDelBtn->TabIndex = 1;
			this->SolveDelBtn->UseVisualStyleBackColor = true;
			// 
			// SolveEditBtn
			// 
			this->SolveEditBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SolveEditBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SolveEditBtn.Image")));
			this->SolveEditBtn->Location = System::Drawing::Point(42, 244);
			this->SolveEditBtn->Name = L"SolveEditBtn";
			this->SolveEditBtn->Size = System::Drawing::Size(30, 30);
			this->SolveEditBtn->TabIndex = 2;
			this->SolveEditBtn->UseVisualStyleBackColor = true;
			// 
			// SettingsGroupBox
			// 
			this->SettingsGroupBox->Controls->Add(this->SolveBtn);
			this->SettingsGroupBox->Location = System::Drawing::Point(126, 115);
			this->SettingsGroupBox->Name = L"SettingsGroupBox";
			this->SettingsGroupBox->Size = System::Drawing::Size(351, 280);
			this->SettingsGroupBox->TabIndex = 3;
			this->SettingsGroupBox->TabStop = false;
			this->SettingsGroupBox->Text = L"Условия";
			// 
			// SolveBtn
			// 
			this->SolveBtn->Location = System::Drawing::Point(270, 244);
			this->SolveBtn->Name = L"SolveBtn";
			this->SolveBtn->Size = System::Drawing::Size(75, 30);
			this->SolveBtn->TabIndex = 0;
			this->SolveBtn->Text = L"Построить";
			this->SolveBtn->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->col0, this->col1,
					this->col2, this->col3, this->col4, this->col5, this->col6
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(866, 404);
			this->dataGridView1->TabIndex = 0;
			// 
			// SolveGrid
			// 
			this->SolveGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->SolveGrid->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SolveGrid->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->SolveGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->SolveGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->const_var_x,
					this->const_var_u
			});
			this->SolveGrid->Dock = System::Windows::Forms::DockStyle::Top;
			this->SolveGrid->Location = System::Drawing::Point(3, 16);
			this->SolveGrid->Name = L"SolveGrid";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->Padding = System::Windows::Forms::Padding(1, 0, 0, 0);
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SolveGrid->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->SolveGrid->RowHeadersVisible = false;
			this->SolveGrid->RowTemplate->DividerHeight = 1;
			this->SolveGrid->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->SolveGrid->Size = System::Drawing::Size(108, 219);
			this->SolveGrid->TabIndex = 3;
			// 
			// const_var_x
			// 
			this->const_var_x->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			dataGridViewCellStyle1->Format = L"N6";
			dataGridViewCellStyle1->NullValue = L"0";
			this->const_var_x->DefaultCellStyle = dataGridViewCellStyle1;
			this->const_var_x->Frozen = true;
			this->const_var_x->HeaderText = L"X0";
			this->const_var_x->Name = L"const_var_x";
			this->const_var_x->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->const_var_x->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->const_var_x->Width = 54;
			// 
			// const_var_u
			// 
			this->const_var_u->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			dataGridViewCellStyle2->Format = L"N6";
			dataGridViewCellStyle2->NullValue = L"0";
			this->const_var_u->DefaultCellStyle = dataGridViewCellStyle2;
			this->const_var_u->Frozen = true;
			this->const_var_u->HeaderText = L"U0";
			this->const_var_u->Name = L"const_var_u";
			this->const_var_u->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->const_var_u->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->const_var_u->Width = 53;
			// 
			// col0
			// 
			this->col0->HeaderText = L"i";
			this->col0->Name = L"col0";
			this->col0->ReadOnly = true;
			// 
			// col1
			// 
			this->col1->HeaderText = L"Xi";
			this->col1->Name = L"col1";
			this->col1->ReadOnly = true;
			// 
			// col2
			// 
			this->col2->HeaderText = L"hi";
			this->col2->Name = L"col2";
			this->col2->ReadOnly = true;
			// 
			// col3
			// 
			this->col3->HeaderText = L"Vi";
			this->col3->Name = L"col3";
			this->col3->ReadOnly = true;
			// 
			// col4
			// 
			this->col4->HeaderText = L"V^i";
			this->col4->Name = L"col4";
			this->col4->ReadOnly = true;
			// 
			// col5
			// 
			this->col5->HeaderText = L"Vi-V^i";
			this->col5->Name = L"col5";
			this->col5->ReadOnly = true;
			// 
			// col6
			// 
			this->col6->HeaderText = L"оц.л.п.";
			this->col6->Name = L"col6";
			this->col6->ReadOnly = true;
			// 
			// Content
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(880, 460);
			this->Controls->Add(this->pageNav);
			this->Controls->Add(this->topMenu);
			this->Name = L"Content";
			this->Text = L"Content";
			this->pageNav->ResumeLayout(false);
			this->pageNav_p1->ResumeLayout(false);
			this->pageNav_p1->PerformLayout();
			this->pageNav_p2->ResumeLayout(false);
			this->topMenu->ResumeLayout(false);
			this->topMenu->PerformLayout();
			this->TaskGroupBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureTask))->EndInit();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GraphChart))->EndInit();
			this->SolveListGroupBox->ResumeLayout(false);
			this->SettingsGroupBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SolveGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
