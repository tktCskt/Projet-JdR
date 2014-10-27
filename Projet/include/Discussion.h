#ifndef DISCUSSION_H
#define DISCUSSION_H


class Discussion
{
    public:
        Discussion();
        virtual ~Discussion();
        char* discussion;
        char** answersList;
        Discussion* nextDiscussion;
    protected:
    private:
};

#endif // DISCUSSION_H
