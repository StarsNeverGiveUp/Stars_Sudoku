#include "controller.h"

void NormalController ::show()
{
    _scene_.showAll();
}

/**
 * 解析命令
 */
void NormalController ::doSomething()
{
    if (_oper_ >= '1' && _oper_ <= '9')
    {
        set(_oper_);
    }
    else
    {
        /* x是列， y是行*/
        switch (_oper_)
        {
        case 's':
            _cursor_.y = (_cursor_.y + 1) % _size_;
            _scene_.changeCursor(_cursor_);
            break;
        case 'w':
            _cursor_.y = (_cursor_.y - 1 + _size_) % _size_;
            _scene_.changeCursor(_cursor_);
            break;
        case 'd':
            _cursor_.x = (_cursor_.x + 1) % _size_;
            _scene_.changeCursor(_cursor_);
            break;
        case 'a':
            _cursor_.x = (_cursor_.x - 1 + _size_) % _size_;
            _scene_.changeCursor(_cursor_);
            break;
        case 'e':
            erase();
            break;
        case 0x1B:
            exit(0);
        default:
            break;
        }
    }

    show();
}

void NormalController :: undoWarning()
{
    vector<point_t> v = _logic_.get(_warning_.key, _warning_.value);

    for(int i = 0; i < v.size(); ++i)
    {
        _scene_.setWarning(v[i], false);
    }
    _scene_.erase(_warning_.key);
    _warning_.valid = false;
}

void NormalController :: set(char value)
{
    erase(); /* 先擦除再写入 */

    if (!_logic_.isChangeable(_cursor_, value)) /* 如果这个值无法被改变， 什么都不做*/
    {
        cout << "Can't be changed" << endl;
        return;
    }

    vector<point_t> temp = _logic_.get(_cursor_, value);

    if (temp.size() <= 0)
    {
        _logic_.set(_cursor_, value);
        _scene_.set(_cursor_, value, Color :: FG_WHITE);
    }
    else
    {
        /* 无效值需要显示冲突 */
        for(int i = 0; i < temp.size(); ++i)
        {
            _scene_.setWarning(temp[i], true);
        }

        _scene_.set(_cursor_, value, Color :: FG_WHITE);
        _warning_.key = _cursor_;
        _warning_.valid = true;
        _warning_.value = value;

    }
}

/**
 * @biref 用于删除现有的点
 */
void NormalController::erase()
{
    bool flag = false;
    
    if (_warning_.valid)
    {
        flag = true;
        undoWarning();
    }
  
    if (!_logic_.isChangeable(_cursor_)) /* 如果这个值无法被改变， 什么都不做*/
    {
        cout << "Can't be changed" << endl;
        return;
    }

    if (!(_warning_.key == _cursor_ && flag)) /* 这个点并不是一个warning点, 才需要erase*/
    {
        _logic_.erase(_cursor_, _scene_.get(_cursor_));
        _scene_.erase(_cursor_);
    }
}

void NormalController :: init()
{
    _scene_.init(_logic_.getInit());
}