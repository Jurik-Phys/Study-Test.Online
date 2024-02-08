import React                           from 'react'
import Header                          from './components/Header/Header'
import NavBar                          from './components/NavBar/NavBar'
import UserSectionSelectPage           from './components/UserSectionSelect/UserSectionSelectPage'
import UserSubsectionSelect            from './components/UserSubsectionSelect/UserSubsectionSelect'
import UserChallengeSelect             from './components/UserChallengeSelect/UserChallengeSelect'
import UserPassingTest                 from './components/UserPassingTest/UserPassingTest'
import UserPassingTestTmp              from './components/UserPassingTest/UserPassingTestTmp'
import UserResultTest                  from './components/UserResultTest/UserResultTest'
import AdminTestManage                 from './components/AdminTestManage/AdminTestManage'
import AdminSessionsManage             from './components/AdminSessionsManage/AdminSessionsManage'
import AdminSessionsView               from './components/AdminSessionsView/AdminSessionsView'
import AdminQuestionsManage            from './components/AdminQuestionsManage/AdminQuestionsManage'
import AdminQuestionsView              from './components/AdminQuestionsView/AdminQuestionsView'
import AboutUsPage                     from './components/AboutUs/AboutUsPage'
import {BrowserRouter, Routes, Route}  from 'react-router-dom'
import './App.css';

function App() {
  return (
    <BrowserRouter>
      <div className="fillBackground">
        <div className="app-wrapper">
          <Header />
          <NavBar />
          <Routes>
            <Route path="/"                                    element={<UserSectionSelectPage />} />
            <Route path="/user-section-select"                 element={<UserSectionSelectPage />} />
            <Route path="/user-subsection-select/:testTypeId?" element={<UserSubsectionSelect />} />
            <Route path="/user-challenge-select/:sectionId?"   element={<UserChallengeSelect />} />
            <Route path="/user-passing-test/:sessionId?"       element={<UserPassingTest />} />
            <Route path="/user-passing-test-tmp"               element={<UserPassingTestTmp />} />
            <Route path="/user-result-test/:sessionId?"        element={<UserResultTest />} />
            <Route path="/admin-test-manage"                   element={<AdminTestManage />} />
            <Route path="/admin-sessions-manage"               element={<AdminSessionsManage />} />
            <Route path="/admin-sessions-view"                 element={<AdminSessionsView />} />
            <Route path="/admin-questions-manage"              element={<AdminQuestionsManage />} />
            <Route path="/admin-questions-view"                element={<AdminQuestionsView />} />
            <Route path="/about-us"                            element={<AboutUsPage />} />
          </Routes>
        </div>
      </div>
    </BrowserRouter>
  );
}

export default App;
