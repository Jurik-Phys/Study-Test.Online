import style from "./AdminTestManage.module.css"
import { useNavigate } from "react-router-dom"

const AdminTestManage = () => {
  const navigate = useNavigate();

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>
          Test management
        </div>
        <div className={style.imageBox}>
          <div>
            <img src="sessions.png" alt="Sessions.png" onClick={ ()=>navigate('/admin-sessions-manage')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/admin-sessions-manage')}> Sessions</div>
          </div>
          <div>
            <img src="questions.png" alt="Questions.png" onClick={ ()=>navigate('/admin-questions-manage')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/admin-questions-manage')}>Questions</div>
          </div>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate('/')} >Back to Home</button>
        </div>
      </div>
  );
}


export default AdminTestManage;
