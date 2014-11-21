#include <gtest/gtest.h>
#include <refcnt/refcnt.h>

class TestUsage : public ::testing::Test {

public:

    // this class wrapps RefCnt, similar to normal usage
    class TestRefCnt : public RefCnt {
    public:
        TestRefCnt() :
            RefCnt(),
            delete_marker_(NULL) {}

        void setDelMarker(bool * value) {
            delete_marker_ = value;
            if (delete_marker_ != NULL) {
                *delete_marker_ = false;
            }
        }
    protected:
        ~TestRefCnt() {
            if (delete_marker_ != NULL) {
                *delete_marker_ = true;
            }
        }
    private:
        // if provided, is set to true when this instance is deleted
        bool * delete_marker_;
    };

public:
    TestUsage () {}
    virtual ~TestUsage () {}

    void SetUp(){
        t_1 = new TestRefCnt ();
        t_2 = new TestRefCnt ();
        t_2->acquire();
        t_3 = new TestRefCnt ();
        t_3->acquire();
        t_3->acquire();
        t_4 = new TestRefCnt ();
        t_4->acquire();
        t_4->acquire();
        t_4->acquire();
    }
    void TearDown(){
        t_1->forceRelease();
        t_2->forceRelease();
        t_3->forceRelease();
        t_4->forceRelease();
    }

public:

    TestRefCnt * t_1;
    TestRefCnt * t_2;
    TestRefCnt * t_3;
    TestRefCnt * t_4;

};

TEST_F(TestUsage, initial_state) {
    EXPECT_EQ(t_1->referenceCount (), 1);
    EXPECT_EQ(t_2->referenceCount (), 2);
    EXPECT_EQ(t_3->referenceCount (), 3);
    EXPECT_EQ(t_4->referenceCount (), 4);
}

TEST_F(TestUsage, increasing) {
    t_1->acquire();
    t_2->acquire();
    t_3->acquire();
    t_4->acquire();
    EXPECT_EQ(t_1->referenceCount (), 2);
    EXPECT_EQ(t_2->referenceCount (), 3);
    EXPECT_EQ(t_3->referenceCount (), 4);
    EXPECT_EQ(t_4->referenceCount (), 5);
}

TEST_F(TestUsage, decreasing) {
    t_2->release();
    t_3->release();
    t_4->release();
    EXPECT_EQ(t_2->referenceCount (), 1);
    EXPECT_EQ(t_3->referenceCount (), 2);
    EXPECT_EQ(t_4->referenceCount (), 3);
}

TEST_F(TestUsage, delete_at_zero) {
    bool t_loc_1_deleted;
    TestUsage::TestRefCnt * t_loc_1 =
            new TestUsage::TestRefCnt();
    t_loc_1->setDelMarker (&t_loc_1_deleted);
    ASSERT_FALSE (t_loc_1_deleted);
    t_loc_1->release ();
    ASSERT_TRUE (t_loc_1_deleted);
}
