#pragma once

#include <string>
#include <vector>

struct Text
{
    std::string str;
    int color = 0;
};

class Memento
{
public:
    Memento(const Text& text) : text_(text) { }

    Text getText()
    {
        return text_;
    }

protected:
    Text text_;
};

class TextEditor
{
public:
    TextEditor(const std::string& text, int color = 0)
    {
        text_.str = text;
        text_.color = color;
    }

    std::string getText()
    {
        return text_.str;
    }

    void setText(std::string text, int color = 0)
    {
        text_.str = text;
        text_.color = color;
    }

    void save()
    {
        history_.push_back(text_);
    }

    void undo()
    {
        if (!history_.size())
        {
            return;
        }
        Text temp = history_.back().getText();
        text_.color = temp.color;
        text_.str = temp.str;
        history_.pop_back();
    }

private:
    Text text_;
    std::vector<Memento> history_;
};
